#pragma once
#include <stdint.h>

#define PROGMEM
#include "magickey_data.h"

typedef struct {
	const uint16_t *dict;
	const uint8_t *completions;
	int dict_size;
	int completions_size;
} trie2_t;

void test_trie2();
