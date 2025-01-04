#if __GNUC__ > 4 && __GNUC__ <=14
# pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

#include "stack.h"
#include <stdio.h>

[[deprecated("implementation")]]
stack* stack_init(stack* s, size_t size) {
	if (s) {
		if (size) {
			*s = (stack){
				.size = size,
				.top = 0,
			};
		} else {
			*s = (stack){ };
		}
	}
	return s;
}

[[deprecated("implementation")]]
bool stack_isempty(stack* s) {
	return s && s->top == 0 ? true : false; 
}

[[deprecated("implementation")]]
void stack_push(stack* s, double x) {
	if (s) {
		if (s->top == s->size) {
			fprintf(stderr, "overflow\n");
		} else {
			s->ar[s->top] = x;
			++(s->top);
		}
	}
}

[[deprecated("implementation")]]
double stack_pop(stack *s) {
	double ret = -1.0/0.0;
	if (s) {
		if (stack_isempty(s)) {
			fprintf(stderr, "underflow\n");
		} else {
			--(s->top);
			ret = s->ar[s->top];
		}
	}
	return ret;
}
