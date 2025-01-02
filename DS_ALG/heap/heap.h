#ifndef HEAP_H
#define HEAP_H 1

#include <stddef.h>
#include <stdlib.h>

#include "c23_fallback.h"

typedef struct heap heap;
struct heap {
	size_t capacity   [[deprecated("private")]];
	size_t heap_size  [[deprecated("private")]];
	double data[];
};

/**
 * heap_init - Initialise a heap object with a capacity of `cap`.
 * Only use this function on an unitialised heap. Each heap initialised
 * with this function must be destroyed with a call to `heap_destroy`.
 * @Returns: a pointer to the initialised heap object, null otherwise.*/
heap* heap_init(heap* h, size_t cap);

/**
 * heap_delete - delete a heap object. `h` must have been allocated with
 * a call to `heap_new`.
 */
inline void heap_delete(heap* h) {
	free(h);
	h = 0;
}

/**
 * heap_new - Allocate and initialise a heap object with a capacity
 * of `capacity`. Each allocated heap must be deleted with a call to
 * `heap_delete`.
 */
[[nodiscard("pointer to allocated heap dropped.")]]
[[__gnu__::__malloc__, __gnu_free__(heap_delete)]]
inline
heap* heap_new(size_t capacity) {
	size_t size = offsetof(heap, data) + sizeof(double[capacity]);
	if (size < sizeof(heap))
		size = sizeof(heap);
	return heap_init((heap* )malloc(size), capacity);
}

/**
 * parent - get the parent index of the node at index `i`.
 */
inline
size_t parent(size_t idx) {
	return (idx - 1) >> 1;
}

/**
 * left_child - get the index of the left child of the node at index `i`.
 */
inline
size_t left_child(size_t idx) {
	return (idx << 1) + 1;
}

/**
 * right_child - get the index of the right child of the node at index `i`.
 */
inline
size_t right_child(size_t idx) {
	return (idx << 1) + 2;
}

/**
 * heap_resize - resize the heap to the new capacity `ncap`.
 * @Returns: pointer to resized heap object.
 */
[[nodiscard("returned pointer replaces function argument.")]]
heap* heap_resize(heap* h, size_t ncap);

/**
 * heap_capacity - get the capacity of a heap object.
 * @Returns: capactiy of the heap. 0 if heap pointer is null.
 */
size_t heap_capacity(heap const* h);

/**
 * heap_size - get the number of elements currently stored in the heap.
 * @Returns: element count. O if heap pointer is null.
 */
size_t heap_size(heap const* h);

/**
 * max_heapify - maintains the max-heap property of a max-heap, h.
 * @Returns: void.
 */
void max_heapify(heap* h, size_t idx);

/**
 * build_max_heap - generate a max-heap from an unordered array of size n
 * @Returns: pointer to the created heap, null otherwise.
 */
[[nodiscard("pointer to created max-heap dropped.")]]
heap* build_max_heap(size_t n, double const ar[static n]);

/**
 * heap_element - returns a pointer to position `pos` in heap `h`.
 * @Returns: pointer to element at `pos` of the heap, null otherwise.
 **/
double* heap_element(heap const* h, size_t pos);
#endif
