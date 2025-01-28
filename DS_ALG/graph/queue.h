#ifndef MY_QUEUE_H
#define MY_QUEUE_H 1

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct queue queue;
struct queue {
	unsigned len   [[deprecated("private")]]; // Number of elements.
	unsigned cap   [[deprecated("private")]]; // Maximum capacity.
	unsigned start [[deprecated("private")]]; // Start of queue.
	float ar[];
};


queue* queue_init(queue* q, unsigned cap);

static
inline
void queue_delete(queue* q) {
	free(q);
	q = 0;
}

[[nodiscard("Pointer to allocated queue dropped.")]]
[[__gnu__::__malloc__]]
static
inline
queue* queue_new(unsigned cap) {
	size_t size = offsetof(queue, ar) + sizeof(unsigned[cap]);
	if (size < sizeof(queue))
		size = sizeof(queue);
	return queue_init((queue*)calloc(1, size), cap);
}

/**
 * queue_enqueue - adds an entry to the end of the queue.
 * @q: pointer to the queue object.
 * @val: value to add to the end of the queue.
 * @Returns pointer to the queue or null if unsuccessful.
 */
queue* queue_enqueue(queue* q, float val);

/**
 * queue_dequeue - removes and returns the element at the head of
 * the queue.
 * @q: pointer to the queue object.
 * @Returns: val at the head of the queue. Otherwise, NAN.
 */
float queue_dequeue(queue* q);

/**
 * queue_getlength - returns the number of elements in the queue.
 * @q: pointer to the queue object.
 * @Returns: count of the elements stored in the queue.
 */
unsigned queue_getcount(queue const* q);

/**
 * queue_fput - prints out the contents of the queue to stream `s`.
 * @q: pointer to the queue object.
 * @s: pointer to the stream.
 * @Returns: void.
 */
void queue_fput(queue const* q, FILE* s);

#endif
