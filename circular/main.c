#include <stdio.h>

#include "circular.h"


int main(void){
	circular* c = circular_new(10);
	printf("Size of the circular array: %zu\n", circular_getmaxlength(c));
	circular_setstartindex(c, 8);

	double start = 13.7;
	for (size_t i = 0; i < 5; i++)
	{
		c = circular_append(c, start * (i + 1));
	}
	printf("Current number of values: %zu\n", circular_getlength(c));
	printf("Removing earliest entry into the circular array\n");
	
	double value = circular_pop(c);
	printf("Earliest entry: %.2f\n", value);

	printf("Current number of values: %zu\n", circular_getlength(c));

	for (size_t i = 0; i < circular_getlength(c); i++){
		printf("[%zu] = %.2f\n", i, *circular_element(c, i));
	}

	printf("Resizing the circular array\n");
	circular* new_c = circular_resize(c, 6);
	if (!new_c) {
		printf("Could not resize the array");
	} else {
		printf("New size of the circular array: %zu\n", circular_getmaxlength(new_c));

		for (size_t i = 0; i < circular_getlength(c); i++){
			printf("[%zu] = %.2f\n", i, *circular_element(c, i));
		}
	}

	circular_delete(new_c);
	return 0;
}
