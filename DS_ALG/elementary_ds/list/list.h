#ifndef MY_LIST_H
#define MY_LIST_H 1

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * node - a new type that defines an element in a doubly linked list.
 * Each element has a `key` attribute and a `np` pointer attribute
 * which is the xor of the two other attributes of the element: `next`
 * and `prev` pointer attributes.
 */
typedef struct node node;
struct node {
	double key; // Key attribute of an element.
	//node* np;   // XOR of prev and next attributes of an element.
	node* next; // prev attribute of an element.
	node* prev; // next attribute of an element.
};

/**
 * node_init - initialises a node element. Only utilise this function on an
 * uninitialised node element.
 * @n: pointer to a node element.
 * @k: key attribute to initialise the node element with.
 * @Returns: pointer to the initialised element, null otherwise.*/
node* node_init(node* n, double k);

/**
 * list - a new type that defines a doubly linked list. It utilises a sentinel
 * object `nil` to simplify the boundary conditions of the list.
 */
typedef struct list list;
struct list {
	node nil; // Sentinel object for use in a linked list.
};

/**
 * list_init - initialises a linked list. Only utilise this function on an
 * uninitialised list. Each list initialised with this function MUST be destroyed
 * by a call to the function `list_destroy`.
 * @l: pointer to a doubly-linked list.
 * @Returns: pointer to the initialised list, null otherwise.
 */
list* list_init(list* l);

/**
 * list_destroy - destroys all the elements of a linked list. The list MUST have
 * been initialised by a call to `list_init`.
 * @Returns: void.
 */
void list_destroy(list* l);

/**
 * list_insert - insert an element `x` into the list following object `y`. If inserting
 * at the head of the list, `y = L.nil`. If inserting at the tail of the list, `y = L.nil.prev`.
 */
void list_insert(node* x, node* y);

/**
 * list_search - searches for an element with the key attribute `k` in the 
 * doubly linked list `l`.
 * @Returns: pointer to the node element that has the given key attribute,
 * otherwise null.
 */
node* list_search(list* l, double k);

/**
 * list_delete - deletes element `x` from the linked list.
 * @Returns: void.
 */
void node_delete(node* x);
/**
 * print_list - print out the elements of the doubly linked list `l`.
 * @Returns:void.
 */
void print_list(list* l); 

[[nodiscard("pointer to allocated linked list dropped.")]]
[[__gnu__::__malloc__]]
inline
list* list_new(void) {
	return list_init((list*)malloc(sizeof(list)));
}

/**
 * list_delete - deletes the linked list. The list MUST have been allocated
 * with a call to `list_new`
 * @Returns: void.
 */
inline
void list_delete(list* l) {
	list_destroy(l);
	free(l);
}

[[nodiscard("pointer to allocated node element dropped.")]]
[[__gnu__::__malloc__]]
inline
node* node_new(double k) {
	return node_init((node*)malloc(sizeof(node)), k);
}

#define PTR_XOR(a, b) ((node*)((uintptr_t)(a) ^ (uintptr_t)(b)))
#endif
