#include <stdio.h>

#include "circular.h"


int main(void) {
	printf("Circular size: %zu\nSize_t size: %zu\n", sizeof(circular), sizeof(size_t));
	circular* c = circular_new(3);

	c = circular_append(c, 5.6);
	c = circular_append(c, 10.2);

	printf("Element count: %zu\n", circular_getlength(c));
	double old_value = circular_pop(c);
	printf("Top element: %g\n", old_value);

	printf("Element count: %zu\n", circular_getlength(c));

	circular_delete(c);
	c = nullptr;
	return 0;
}
