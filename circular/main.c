#include <stdio.h>

#include "circular.h"


int main(void){
	circular* c = circular_new(10);

	c = circular_append(c, 22.5);
	c = circular_append(c, 34.6);
	double value = circular_pop(c);
	c = circular_append(c, 100.0);
	printf("Oldest value: %.2f\n", value);
	printf("Length of values: %zu\n", circular_getlength(c));

	circular_delete(c);
	return 0;
}
