#include "list.h"

node* node_init(node *n, double k) {
	if (n) {
		n->key = k;
		n->next = nullptr;
		n->prev = nullptr;
	}
	return n;
}

list* list_init(list *l) {
	if (l) {
		l->nil.key = 1.0 / 0.0;
		l->nil.next = &l->nil;
		l->nil.prev = &l->nil;
	}
	return l;
}

void list_destroy(list *l) {
	if (l) {
		node* cur = l->nil.next;

		while (cur != &l->nil) {
			node* prev = cur;
			cur = cur->next;
			free(prev);
		}
	}
}

void list_insert(node* x, node* y) {
	if (x && y) {
		x->next = y->next;
		x->prev = y;
		y->next->prev = x;
		y->next = x;
	}
}

void node_delete(node* x) {
	if (x) {
		x->prev->next = x->next;
		x->next->prev = x->prev;
		free(x);
		x = nullptr;
	}
}

node* list_search(list* l, double k) {
	// key was found in the sentinel, hence was not really in the list.
	node* ret = nullptr;
	if (l) {
		// store the key in the sentinel to guarantee its presence.
		l->nil.key = k;
		// start at the head of the list.
		node* x = l->nil.next;
		while (x->key != k)
			x = x->next;
		// found the key in element x.
		if (x != &l->nil)
			ret = x;
	}
	return ret;
}

void print_list(list* l) {
	if (l) {
		node* cur = l->nil.next;

		while (cur != &l->nil) {
			printf("(%g) => ", cur->key);
			cur = cur->next;
		}
		printf(" [SENTINEL]-|\n");
	}
}
