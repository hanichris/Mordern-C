#include "headers/quick.h"


static void swap(double* ptr_a, double* ptr_b){
	double temp = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = temp;
}

static int partition(double ar[], int low, int high) {
	int firsthigh = low;
	int j = high;

	for (int i = low; i < high; i++) {
		if (ar[i] < ar[j]) {
			swap(&ar[i], &ar[firsthigh]);
			firsthigh++;
		}
	}
	swap(&ar[j], &ar[firsthigh]);
	return firsthigh;
}

void quicksort(double ar[], int low, int high) {
	if (high - low > 0) {
		int pivot = partition(ar, low, high);
		quicksort(ar, low, pivot - 1);
		quicksort(ar, pivot + 1, high);
	}
}
