#include <stdio.h>
#include <string.h>

void merge(double* ar, size_t p, size_t q, size_t r) {
	if(ar) {
		size_t left = q - p + 1;
		size_t right = r - q;

		double left_buffer[left] = { };
		double right_buffer[right] = { };
		memcpy(left_buffer, ar, sizeof left_buffer);
		memcpy(right_buffer, ar + left, sizeof right_buffer);
		
		unsigned i = 0;
		unsigned j = 0;
		size_t k = p;
		while (i < left && j < right) {
			if (left_buffer[i] <= right_buffer[j])
				ar[k++] = left_buffer[i++];
			else
				ar[k++] = right_buffer[j++];
		}

		while (i < left)
			ar[k++] = left_buffer[i++];
		while (j < right)
			ar[k++] = right_buffer[j++];
	}
}

void merge_sort(double* ar, size_t p, size_t r) {
	if (ar && p < r) {
		size_t q = p + (r - p) / 2;
		
		merge_sort(ar, p, q);
		merge_sort(ar, q + 1, r);

		merge(ar, p, q, r);
	}
}


int main(void) {

	double ar[5] = {-8, 91, 13, 4, 101};

	merge_sort(ar, 0, 4);
	bool flag = true;
	for (unsigned i = 0; i < 4; i++)
		if (ar[i] > ar[i + 1]) {
			flag = false;
			break;
		}
	printf("Is Array sorted? %s\n", flag ? "YES" : "NO");

	return 0;
}
