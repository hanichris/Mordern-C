#include "headers/merge.h"
#include <stdio.h>
static void merge(double ar[], int left, int middle, int right) {
	int size_n = (middle - left) + 1;
	int size_m = right - middle;

	double queue_n[size_n] = {};
	double queue_m[size_m] = {};

	for (int i = 0; i < size_n; i++) queue_n[i] = ar[left + i];
	for (int i = 0; i < size_m; i++) queue_m[i] = ar[middle + 1 + i];

	int i = 0;
	int j = 0;
	int k = left;
	while (i < size_n && j < size_m) {
		if (queue_n[i] <= queue_m[j]) {
			ar[k++] = queue_n[i++];
		} else {
			ar[k++] = queue_m[j++];
		}
	}

	while (i < size_n) ar[k++] = queue_n[i++];
	while (j < size_m) ar[k++] = queue_m[j++];
}

void msort(double ar[], int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;

		msort(ar, left, middle);
		msort(ar, middle + 1, right);
		
		merge(ar, left, middle, right);
	}
}

