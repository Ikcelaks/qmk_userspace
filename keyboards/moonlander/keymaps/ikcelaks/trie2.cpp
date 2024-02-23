#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "trie2.h"
#include "stack.h"
#include "util2.h"

#define KEY_BUFFER_MAX_LENGTH MAGICKEY_MAX_LENGTH
#define TDATA(i) trie->dict[i]
#define CDATA(i) trie->completions[i]

//////////////////////////////////////////////////////////////////////////////////
typedef struct {
	char data[KEY_BUFFER_MAX_LENGTH];
	int size;
	// result data
	const char *completion;
	int complete_len;
    int func_num;
	int num_backspaces;
} search_buffer_t;

//////////////////////////////////////////////////////////////////////////////////
typedef struct trie2_visitor trie2_visitor_t;
typedef void (*trie2_visitor_cb_t)(trie2_visitor_t *, int, int, const char *);
struct trie2_visitor {
	stack_t				stack;
	trie2_visitor_cb_t	cb_func;
	void				*cb_data;
};

//////////////////////////////////////////////////////////////////////////////////
// traverse trie and call v->cb_func at each MATCH node
void traverse_trie2(const trie2_t *trie, int offset, trie2_visitor_t *v)
{
	assert(offset < trie->dict_size);
	uint16_t code = TDATA(offset);
	assert(code);
	// MATCH node
	if (code & 0x8000) {
		// Traverse down child node if this isn't the only match
		if (code & 0x4000)
			traverse_trie2(trie, offset+2, v);
		printf("offset %d: ", offset);
		const int bspaces = (code & 0x3F);
		const int func = (code >> 11 & 0x07);
		const int complete_offset = TDATA(offset+1);
		const char *completion = (const char *)&CDATA(complete_offset);
		v->cb_func(v, bspaces, func, completion);
	}
	// BRANCH node
	else if (code & 0x4000) {
		//printf("BRANCH node at offset %d\n", offset);
		code &= 0x3FFF;
		for (; code; offset += 2, code = TDATA(offset)) {
			// Get 16bit offset to child node
			const int child_offset = TDATA(offset+1);
			// Traverse down child node
			stack_push(&v->stack, keycode_to_char(code));
			traverse_trie2(trie, child_offset, v);
			stack_pop(&v->stack);
		}
	}
	// Chain node
	else {
		//printf("CHAIN node at offset %d\n", offset);
		// Travel down chain until we reach a zero byte
		const int prev_stack_size = v->stack.size;
		for (; code; code = TDATA(++offset))
			stack_push(&v->stack, keycode_to_char(code));
		// After a chain, there should be a leaf or branch
		traverse_trie2(trie, offset+1, v);
		v->stack.size = prev_stack_size;
	}
}
//////////////////////////////////////////////////////////////////////////////////
bool search_trie2(const trie2_t *trie, int offset, trie2_visitor_t *v)
{
	assert(offset < trie->dict_size);
	search_buffer_t *search = (search_buffer_t*)v->cb_data;
	uint16_t code = TDATA(offset);
	assert(code);
	// MATCH node if bit 15 is set
	if (code & 0x8000) {
		// If bit 14 is also set, there's a child node after the completion string
		if ((code & 0x4000) && search_trie2(trie, offset+2, v))
			return true;
		// If no better match found deeper, this is the result!
		const int bspaces = (code & 0x3F);
        const int func = (code >> 11 & 0x7);
		const int complete_offset = TDATA(offset+1);
		const char *completion = (const char *)&CDATA(complete_offset);
		v->cb_func(v, bspaces, func, completion);
		// Found a match so return true!
		return true;
	}
	// BRANCH node if bit 14 is set
	if (code & 0x4000) {
		if ((v->stack.size+1) > search->size)
			return false;
		code &= 0x3FFF;
		const char cur_char = search->data[search->size - (v->stack.size+1)];
		// find child that matches our current buffer location
		for (; code; offset += 2, code = TDATA(offset)) {
			const char c = keycode_to_char(code);
			if (cur_char == c) {
				// Get 15bit offset to child node
				const int child_offset = TDATA(offset+1);
				// Traverse down child node
				stack_push(&v->stack, c);
				const bool res = search_trie2(trie, child_offset, v);
				stack_pop(&v->stack);
				return res;
			}
		}
		// Couldn't go deeper, so return false.
		return false;
	}
	// No high bits set, so this is a chain node
	// Travel down chain until we reach a zero code, or we no longer match our buffer
	const int prev_stack_size = v->stack.size;
	for (; code; code = TDATA(++offset)) {
		const char c = keycode_to_char(code);
		stack_push(&v->stack, c);
		if (v->stack.size > search->size ||
			c != search->data[search->size - v->stack.size]) {
			v->stack.size = prev_stack_size;
			return false;
		}
	}
	// After a chain, there should be a leaf or branch
	const bool res = search_trie2(trie, offset+1, v);
	v->stack.size = prev_stack_size;
	return res;
}

//////////////////////////////////////////////////////////////////////////////////
void print_traverse_cb2(trie2_visitor_t *v, int bspaces, int func, const char *completion)
{
	printf("  depth %d: ", v->stack.size);
    printf(" -> %s (bspc: %d, func: %d)\n", completion, bspaces, func);

	if (v->cb_data) {
		int entries = *(int*)v->cb_data;
		*(int*)v->cb_data = entries + 1;
	}
}

//////////////////////////////////////////////////////////////////////////////////
void print_search_cb2(trie2_visitor_t *v, int bspaces, int func, const char *completion)
{
	printf("  depth %d: ", v->stack.size);
	stack_print(&v->stack);
    search_buffer_t *search = (search_buffer_t*)v->cb_data;
    char last_char;
    int i;
    switch (func) {
        case 1: // repeat
            i = search->size - 1;
            last_char = search->data[i];
            while ((last_char == '*' || last_char == '@') && i >= 0) {
                last_char = search->data[--i];
            }
            search->data[search->size-1] = last_char;
	        printf(" -> %s%c (bspc: %d, func: %d)\n", completion, last_char, bspaces, func);
            printf("  new buffer: %s", search->data);
            printf("\n");
            break;
        case 2: // one-shot-shift
	        printf(" -> %s (bspc: %d, func: %d)\n", completion, bspaces, func);
	        printf("  Activating One-Shot-Shift\n");
            break;
	    default:
            printf(" -> %s (bspc: %d, func: %d)\n", completion, bspaces, func);
    }

	if (v->cb_data) {
		int entries = *(int*)v->cb_data;
		*(int*)v->cb_data = entries + 1;
	}
}
//////////////////////////////////////////////////////////////////////////////////
void test_traverse2(trie2_t *trie)
{
	printf("Traversing Trie2:\n");
	int entries = 0;
	trie2_visitor_t visitor;
	visitor.stack.size = 0;
	visitor.cb_data = (void*)&entries;
	visitor.cb_func = print_traverse_cb2;
	traverse_trie2(trie, 0, &visitor);
	printf("Found %d entries.\n\n", entries);
}
//////////////////////////////////////////////////////////////////////////////////
void test_search2(const trie2_t *trie, const char *buffer)
{
	printf("Searching Trie2 for '%s':\n", buffer);
	search_buffer_t search;
	strcpy(search.data, buffer);
	search.size = (int)strlen(buffer);
	trie2_visitor_t visitor;
	visitor.stack.size = 0;
	visitor.cb_data = (void*)&search;
	visitor.cb_func = print_search_cb2;
	search_trie2(trie, 0, &visitor);
}
//////////////////////////////////////////////////////////////////////////////////
void test_trie2()
{
	trie2_t trie2 = {
		magickey_data,
		magickey_completions_data,
		DICTIONARY_SIZE,
		COMPLETIONS_SIZE
	};
	test_traverse2(&trie2);
	// Test search
	test_search2(&trie2, "i*");
	test_search2(&trie2, ":sti@");
	test_search2(&trie2, "stati*");
	test_search2(&trie2, "bo*");
	test_search2(&trie2, "judge@");
	test_search2(&trie2, "cop*");
	test_search2(&trie2, "beh@");
	test_search2(&trie2, ":beh@");
	test_search2(&trie2, "cat*");
	test_search2(&trie2, ":ex@");
	test_search2(&trie2, "j*");
	test_search2(&trie2, ":i@");
	test_search2(&trie2, ":i@m");
	test_search2(&trie2, ":i@d");
	test_search2(&trie2, ":i@l");
	test_search2(&trie2, "o@");
	test_search2(&trie2, ".@");
}

int main()
{
    test_trie2();
}
