#ifndef MY_STACK_H
#define MY_STACK_H 1

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct stack stack;
struct stack {
	size_t size   [[deprecated("private")]];
	size_t top    [[deprecated("private")]];
	double ar[];
};

/**
 * stack_isempty - tests to see if the stack is empty.
 */
bool stack_isempty(stack* s);

/**
 * stack_push - push an entry to the top of the stack.
 */
void stack_push(stack* s, double x);

/**
 * stack_pop - remove and return the element from the top
 * of the stack.
 */
double stack_pop(stack* s);

/**
 * stack_init - initialise a stack object with a capacity of `size`.
 * Only use this function on an uninitialised stack.
 */
stack* stack_init(stack* s, size_t size);

/**
 * stack_delete - delete a stack object. `s` must have been allocated
 * with a call to `stack_new`.
 */
inline
void stack_delete(stack* s) {
	free(s);
	s = nullptr;
}

[[nodiscard("pointer to allocated stack dropped.")]]
[[__gnu__::malloc]]
inline
stack* stack_new(size_t n) {
	size_t size = offsetof(stack, ar) + sizeof(double[n]);
	if (size < sizeof(stack))
		size = sizeof(stack);
	return stack_init((stack* )malloc(size), n);
}

#endif
