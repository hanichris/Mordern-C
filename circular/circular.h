#ifndef circular_h
#define circular_h

#include <stdlib.h>

/**
 * ciruclar - an opaque type for a circular buffer for double values.
 *
 * The data structure allows for the addition of double values in the
 * rear and for their removal from the front. Each such structure
 * will have a maximal allowed number of values to hold. 
 */
typedef struct circular circular;

/**
 * circular_append - append a new element with the value `value` to the
 * end of `c`.
 * @c: pointer to a circular type.
 * @value: a value to append to the end of `c`.
 * Return: `c` if the new element could be appended, 0 otherwise.
 */
circular* circular_append(circular* c, double value);

/**
 * circular_pop - removes the oldest element from `c` and returns its value.
 * @c: a pointer to a circular type.
 * Return: the removed element if it exists, 0.0 otherwise.
 */
double circular_pop(circular* c);

/**
 * circular_element - return a pointer to position `pos` in buffer c.
 * @c: pointer to a circular type.
 * @pos: position in the circular buffer.
 * Return: pointer to the pos' element of the buffer, 0 otherwise.
 */
double* circular_element(circular* c, size_t pos);

/**
 * circular_init - initialize a circular buffer with maximally `max_len`
 * elements. Only use this function on uninitialised buffer.
 * Each buffer initialised with this function must be destroyed with a
 * call to `circular_destroy`.
 * @c: pointer to a circular type.
 * @max_len: maximum size of the circular buffer.
 * Return: pointer to the initialized buffer.
 */
circular* circular_init(circular* c, size_t max_len);

/**
 * circular_destroy - destroy circular buffer c.
 * c must have been initialised with a call to `circular_init`.
 * @c: pointer to a circular type.
 */
void circular_destroy(circular* c);

/**
 * circular_new - allocate and initialize a circular buffer with maximally
 * len elements.
 * Each buffer that is allocated with this function must be deleted with
 * a call to `circular_delete`.
 * @len: maximum size of the circular buffer.
 */
circular* circular_new(size_t len);

/**
 * circular_delete - delete circular buffer c.
 * c must have been allocated with a call to `circular_new`.
 * */
void circular_delete(circular* c);

/**
 * circular_resize - resize to capacity max_len.
 * @c: pointer to a circular type.
 * @max_len: resize value.
 * Return: pointer to the resized circular type.
 */
circular* circular_resize(circular* c, size_t max_len);

/**
 * circular_getlength - return the number of elements stored.
 * @c: pointer to a circular type.
 * Return: the current number of elements held by the circular type.
 */
size_t circular_getlength(circular* c);

/**
 * circular_getmaxlength - returns the size of the underlying array.
 * @c: pointer to a circular type.
 * Return: the size of the dynamic array.
 */
size_t circular_getmaxlength(circular* c);

/**
 * circular_setstartindex - set the starting index of the circular array.
 * @c: pointer to a circular type.
 * @start: starting index for the circular array.
 */
void circular_setstartindex(circular* c, size_t start);

#endif
