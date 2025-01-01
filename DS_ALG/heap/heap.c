#if __GNUC__ > 4 && __GNUC__ <= 14
# pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

#include "heap.h"

[[deprecated("implementation")]]
size_t heap_size(heap *h) {
	if (h) {
		return h->heap_size;
	}
	return 0;
}

[[deprecated("implementation")]]
size_t heap_capacity(heap *h) {
	if (h) {
		return h->capacity;
	}
	return 0;
}

[[deprecated("implementation")]]
heap* heap_init(heap *h, size_t cap) {
	if (h) {
		if (cap) {
			*h = (heap) {
				.capacity = cap,
				.data = calloc(cap, sizeof(double)),
			};

			if(!h->data) h->capacity = 0;
		} else {
			*h = (heap) { };
		}
	}
	return h;
}

[[deprecated("implementation")]]
void heap_destroy(heap *h) {
	if (h) {
		free(h->data);
		heap_init(h, 0);
	}
}
