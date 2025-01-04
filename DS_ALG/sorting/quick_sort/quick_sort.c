#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "quick_sort.h"

static
inline
void swap(double* a, double* b) {
	double tmp = *a;
	*a = *b;
	*b = tmp;
}

static
int partition(double* ar, int p, int r) {
	double x = ar[r];
	printf("Pivot: %g\n", x);
	int i = p - 1;
	for (int j = p; j < r; j++)
		if (ar[j] <= x) {
			++i;
			swap(&ar[i], &ar[j]);
		}
	swap(&ar[i+1], &ar[r]);
	return i + 1;
}

void quick_sort(double* ar, int p, int r) {
	if (ar && p < r) {
		int q = partition(ar, p, r);
		quick_sort(ar, p, q - 1);
		quick_sort(ar, q + 1, r);
	}
}

static
int randomized_partition(double* ar, int p, int r) {
	uint32_t i = arc4random() % (r + 1);
	printf("Value chosen randomly: [%u] = %g\n", i, ar[i]);
	swap(&ar[i], &ar[r]);
	return partition(ar, p, r);
}

void randomized_quicksort(double* ar, int p, int r) {
	if (ar && p < r) {
		int q = randomized_partition(ar, p, r);
		randomized_quicksort(ar, p, q - 1);
		randomized_quicksort(ar, q + 1, r);
	}
}
