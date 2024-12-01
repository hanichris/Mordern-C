#include "headers/merge.h"

#include <errno.h>
#include <float.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[argc + 1]) {

	errno = 0;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <[number], ... ,[number]>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int size = argc - 1;
	double nums[size];
	for (int i = 0; i < size; i++) {
		nums[i] = strtod(argv[i + 1], 0);
		if ((errno == ERANGE && (nums[i] == DBL_MAX || nums[i] == DBL_MIN)) || (errno != 0 && nums[i] == 0)) {
			perror("strtod");
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%g\n", nums[i]);
		} else {

			printf("%g, ", nums[i]);
		}
	}

	// TODO: Sort the input using mergeSort algorithm.

	msort(nums, 0, size-1);
	bool isSorted = true;
	for (int i = 0; i < size - 1; i++) {
		if (nums[i] > nums[i + 1]) {
			isSorted = false;
			break;
		}
	}
	printf("Sorted? %s\n", (isSorted ? "YES" : "NO"));
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%g\n", nums[i]);
		} else {
			printf("%g, ", nums[i]);
		}
	}

	// TODO: Sort the input using quickSortalgorithm.
	exit(EXIT_SUCCESS);
}
