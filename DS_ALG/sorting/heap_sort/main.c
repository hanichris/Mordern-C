#include <stdio.h>

#include "heap.h"

int main(int argc, [[maybe_unused]]char* argv[argc]) {
	constexpr double ar[] = {
		[0] = 4,
		[1] = 1,
		[2] = 3,
		[3] = 2,
		[4] = 16,
		[5] = 9,
		[6] = 10,
		[7] = 14,
		[8] = 8,
		[9] = 7,
		[10] = -6,
		[11] = 89,
		[12] = 17,
		[13] = -100,
		[14] = 0,
	};
	size_t N = sizeof(ar) / sizeof(ar[0]);

	printf("Unordered array elements:\n");
	for (unsigned i = 0; i < N; i++) {
		printf("%g, ", ar[i]);
	}
	putchar('\n');

	heap* max_heap = heap_sort(N, ar);
	if (max_heap) {
		printf("\nHeap capacity: %zu\n", heap_capacity(max_heap));
		printf("Count of elements in heap: %zu\n", heap_size(max_heap));
		printf("Sorted heap elements:\n");
		for (unsigned i = 0; i < N; i++) {
			printf("%g, ", max_heap->data[i]);
		}
		putchar('\n');
		heap_delete(max_heap);
	}

	return 0;
}
