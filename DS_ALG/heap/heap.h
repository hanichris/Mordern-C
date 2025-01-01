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
 * heap_resize - resize the heap to the new capacity `ncap`.
 * @Returns: pointer to resized heap object.
 */
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
#endif
