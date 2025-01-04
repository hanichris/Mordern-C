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
	// Pick a random number between [p, r]
	uint32_t i = p + arc4random() % (r - p + 1);
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
