#include <stdio.h>

#include "stack.h"


int main(void) {
	stack* s = stack_new(3);

	double val = stack_pop(s);
	printf("Stack: %g\n", val);

	stack_push(s, 15);
	stack_push(s, -12);
	stack_push(s, 25);
	stack_push(s, 100);

	val = stack_pop(s);
	printf("Stack: %g\n", val);
	val = stack_pop(s);
	printf("Stack: %g\n", val);
	val = stack_pop(s);
	printf("Stack: %g\n", val);
	val = stack_pop(s);
	printf("Stack: %g\n", val);


	stack_delete(s);
	return 0;
}
