#pragma once

//////////////////////////////////////////////////////////////////////////////////
#define STACK_SIZE 256
typedef struct {
	char buffer[STACK_SIZE];
	int size;
} stack_t;

void stack_push(stack_t *s, char c);
void stack_pop(stack_t *s);
void stack_print(stack_t *s);