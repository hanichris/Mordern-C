#if __GNUC__ > 4 && __GNUC__ <= 14
# pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

#include <string.h>

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
			};

		} else {
			*h = (heap) { };
		}
	}
	return h;
}

[[deprecated("implementation")]]
static
inline
size_t heap_getpos(heap const h[static 1], size_t pos) {
	return pos < h->capacity ? pos : 0;
}

[[deprecated("implementation")]]
double* heap_element(const heap *h, size_t pos) {
	double* ret = nullptr;
	if (h) {
		if (pos < h->capacity) {
			pos = heap_getpos(h, pos);
			ret = &h->data[pos];
		}
	}

	return ret;
}

[[deprecated("implementation")]]
void max_heapify(heap* h, size_t idx) {
	if (h) {
		// Assume the current index holds the largest value.
		size_t largest = idx;

		while (true) {
			size_t l = left_child(idx);
			size_t r = right_child(idx);

			// Check if the left child's value is larger than the current node value.
			if (l < heap_size(h)) {
				double* left_val = heap_element(h, l);
				double* cur_val = heap_element(h, idx);
				if (left_val && cur_val && *left_val > *cur_val)
					largest = l;
			}

			// Check if the right child's value is larger than the current largest value.
			if (r < heap_size(h)) {
				double* right_val = heap_element(h, r);
				double* largest_val = heap_element(h, largest);
				if (right_val && largest_val && *right_val > *largest_val)
					largest = r;
			}


			// If the largest is still the current node value, we need not proceed.
			if (largest == idx) break;

			// Swap the current node value with the largest node value.
			double* largest_val = heap_element(h, largest);
			double* cur_val = heap_element(h, idx);
			double tmp = *cur_val;
			*cur_val = *largest_val;
			*largest_val = tmp;

			// Move to the next node for the heapify process.
			idx = largest;
		}

	}
}

[[deprecated("implementation")]]
heap* build_max_heap(size_t n, double const ar[static n]) {
	heap* max_heap = heap_new(n);
	if (max_heap) {
		memcpy(max_heap->data, ar, sizeof(double[n]));
		max_heap->heap_size = n;
		for (int i = (n - 1) >> 1; i >= 0; --i)
			max_heapify(max_heap, i);
	}

	return max_heap;
}
