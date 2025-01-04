#include <stdbool.h>
#include <stdio.h>


static
void insertion_sort(size_t size, double ar[static size]) {
	for (unsigned i = 1; i < size; i++) {
		double key = ar[i];
		int j = i - 1;
		while (j >= 0 && ar[j] > key) {
			ar[j + 1] = ar[j];
			--j;
		}
		ar[j + 1] = key;
	}
}


int main(void) {

	double ar[] = {19.3, 44.5, 36.2, -0.4, 6, -28.7, 59.2, 98, 62.4, 84, 77.7};
	size_t size = sizeof ar / sizeof ar[0];
	insertion_sort(size, ar);

	//printf("Array size: %zu\n", size);
	bool flag = true;
	for(unsigned i = 0; i < size - 1; i++) {
		if (ar[i] > ar[i + 1]){
			flag = false;
			break;
		}
	}
	printf("Is array sorted ? %s\n", flag ? "YES": "NO");
	return 0;
}
