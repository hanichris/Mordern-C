#include <stdio.h>

#include "quick_sort.h"


int main(void) {
	double ar[] = {
		[0] = 34,
		[1] = 19,
		[2] = -45,
		[3] = 22,
		[4] = 101,
		[5] = 2,
		[6] = 0.3,
		[7] = 84.6,
		[8] = 57,
		[9] = 77,
	};

	size_t N = sizeof ar / sizeof ar[0];

	printf("\nArray elements before sorting.\n");
	for (unsigned i = 0; i < N; i++)
		printf("%g ", ar[i]);
	putchar('\n');

	quick_sort(ar,  0, N - 1);

	printf("\nArray elements after sorting.\n");
	for (unsigned i = 0; i < N; i++)
		printf("%g ", ar[i]);
	putchar('\n');

	return 0;
}
