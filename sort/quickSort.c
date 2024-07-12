#include "quick.h"


static void swap(double* ptr1, double* ptr2){
	double temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void quickSort(double ar[], int low, int high){
	if ((high - low) > 0){
		int pivot = partition(ar, low, high);
		quickSort(ar, low, pivot - 1);
		quickSort(ar, pivot + 1, high);
	}
}

int partition(double ar[], int low, int high){
	int firsthigh = low;
	int p = high;

	for(int i = low; i < high; i++){
		if(ar[i] < ar[p]){
			swap(&ar[i], &ar[firsthigh]);
			firsthigh++;
		}
	}
	swap(&ar[p], &ar[firsthigh]);
	return firsthigh;
}
