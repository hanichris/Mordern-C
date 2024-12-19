#ifndef ALLOCATION_H
#define ALLOCATION_H 1

/**
 * circular - a type for a circular buffer with double values.
 * This data structure allows for the addition of double values
 * through the rear and takes them out through the front. Each
 * such structure has a maximal amount of elements that can be
 * stored within it.
 */
typedef struct circular circular;

struct circular {
	size_t start [[deprecated("privat")]];  /* First element. */
	size_t len   [[deprecated("privat")]];  /* Number of elements. */
	size_t cap   [[deprecated("privat")]];  /* Maximum capacity. */
	double* tab  [[deprecated("privat")]];  /* Data array. */
};

/**
 * circular_append - appends a new element with the value @a value
 * to the buffer @a c.
 * @Returns: c if the new element could be appended or null otherwise.
 */
circular* circular_append(circular* c, double value);

/**
 * circular_pop - removes the oldest element from the buffer and returns it.
 * @Returns: the removed element if it exists, 0.0 otherise.
 */
double circular_pop(circular* c);

/**
 * circular_element - return a pointer to position @a pos in buffer @a c.
 * @Returns: a pointer to element pos of the buffer, null otherise.
 */
double* circular_element(circular const* c, size_t pos);


// The following pairs of functions are applied to existing storage. The pair receive
// a pointer to the structure and ensure that space for the data member is allocated
// or freed.

/**
 * circular_init - Initialise a circular buffer @a c with maximally @a cap elements.
 * Only use this function on an uninitialised buffer. Each buffer initilised with
 * this function must be destroyed with a call to `circular_destroy`.
 * @Returns: pointer to the initilised buffer, null otherise.
 */
circular* circular_init(circular* c, size_t cap);

/**
 * circular_destroy - Destroy circular buffer @a c. @a c must have been initialised
 * with a call to `circular_init`.
 * @Returns: void.
 */
void circular_destroy(circular* c);

// The following pairs of functions allocate or deallocate storage for the structure itself.
// They do not access any member of the structure directly, and can be specified as 'inline'.

/**
 * circular_new - Allocate and initialise a circular buffer with maximally len elements.
 * Each buffer that is allocated within this function must be delete with a call to
 * circular_delete.*/
[[nodiscard("pointer to allocated data dropped.")]]
[[__gnu__::__malloc__, __gnu_free__(circular_delete)]]
inline
circular* circular_new(size_t len);

/**
 * circular_delete - Delete a circular buffer. @a c must have been allocated with a call
 * to ciruclar_new.
 */
inline
void circular_delete(circular* c);

// The flexibility of using a dynamically allocated array comes in when we would like to
// resize the array. For regular array variables, the maximum number of elements that could
// be stored is fixed once the object is created.

/**
 * circular_resize - Resize to capacity cap.
 */
[[nodiscard("returned pointer replaces function argument.")]]
circular* circular_resize(circular* c, size_t cap);

/**
 * circular_getlength = Return the number of elements stored.
 */
size_t circular_getlength(circular const* c);
#endif
