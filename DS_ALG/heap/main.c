#include <stdio.h>

#include "heap.h"

int main(int argc, [[maybe_unused]]char* argv[argc]) {

	heap* max_heap = heap_new(10);
	printf("Size of heap type: %zu\n", sizeof *max_heap);

	printf("Heap capacity: %zu\n", heap_capacity(max_heap));
	printf("Count of elements in heap: %zu\n", heap_size(max_heap));

	heap_delete(max_heap);
	return 0;
}
