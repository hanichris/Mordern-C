#if __GNUC__ > 4 && __GNUC__ <= 14
# pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

#include "heap.h"

[[deprecated("implementation")]]
size_t heap_size(heap const* h) {
	return h ? h->heap_size: 0;
}

[[deprecated("implementation")]]
size_t heap_capacity(heap const* h) {
	return h ? h->capacity: 0;
}

[[deprecated("implementation")]]
heap* heap_init(heap *h, size_t cap) {
	if (h) {
		if (cap) {
			*h = (heap) {
				.capacity = cap,
				.data = { }, 
			};

		} else {
			*h = (heap) { };
		}
	}
	return h;
}

