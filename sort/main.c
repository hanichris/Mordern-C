#include "main.h"

int main(void){
	double ar[] = {5.0, 9.0, 2.3, -5.4, 2.9, 10.7, 1.8, 5.5, -4.2, 3.7};
	double ar2[] = {5.0, 9.0, 2.3, -5.4, 2.9, 10.7, 1.8, 5.5, -4.2, 3.7};
	int len = sizeof(ar) / sizeof(ar[0]);


	for(int i = 0; i < len; i++) printf("%g ", ar[i]);

	#if defined(MERGE_SORT_ALGORITHM)
	printf("\n====Sorting using the mergeSort algorithm====");
	mergeSort(ar, 0, len-1);
	#else
	printf("\n====Sorting using the quickSort algorithm====");
	quickSort(ar, 0, len-1);
	#endif
	bool flag = true;
	for(int i = 0; i < len - 1; i++){
		if(ar[i] > ar[i + 1]){
			flag = false;
			break;
		}
	}
	printf("\nSorted? %s\n", (flag == true) ? "Yes" : "No");
	for(int i = 0; i < len; i++) printf("%g ", ar[i]);
	printf("\n");

	return 0;
}
