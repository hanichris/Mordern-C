#include "merge.h"


void mergeSort(double ar[], int left, int right){
	if(left < right){
		int middle = left + (right - left) / 2;
		mergeSort(ar, left, middle);
		mergeSort(ar, middle + 1, right);

		merge(ar, left, middle, right);
	}
}

void merge(double ar[], int left, int middle, int right){
	int N = middle - left + 1;
	int M = right - middle;

	// variable length arrays to serve as temporary storage.
	double queue1[N];
	double queue2[M];

	for(int i = 0; i < N; i++) queue1[i] = ar[left + i];
	for(int i = 0; i < M; i++) queue2[i] = ar[middle + 1 + i];

	int i = 0;
	int j = 0;
	int k = left;
	while(i < N && j < M){
		if(queue1[i] <= queue2[j]) ar[k++] = queue1[i++];
		else {
			ar[k++] = queue2[j++];
		}
	}
	while(i < N) ar[k++] = queue1[i++];
	while(j < M) ar[k++] = queue2[j++];

}
