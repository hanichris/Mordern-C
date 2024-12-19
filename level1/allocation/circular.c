#include <stdlib.h>

#include "circular.h"


[[deprecated("implementation")]]
circular* circular_init(circular* c, size_t cap) {
	if (c) {
		if (cap) {
			*c = (circular) {
				.cap = cap,
				.tab = malloc(sizeof(double[cap])),
			};
			if (!c->tab) c->cap = 0;
		} else {
			*c = (circular) { };
		}
	}
	return c;
}

[[deprecated("implementation")]]
void circular_destroy(circular* c) {
	if (c) {
		free(c->tab);
		circular_init(c, 0);
	}
}


[[deprecated("implementation")]]
static size_t circular_getpos(circular const c[static 1], size_t pos) {
	if (c->cap) {
		pos += c->start;
		pos %= c->cap;
	}
	return pos;
}


[[deprecated("implementation")]]
double* circular_element(circular const* c, size_t pos) {
	double* ret = nullptr;
	if (c) {
		if (pos < c->cap) {
			pos = circular_getpos(c, pos);
			ret = &c->tab[pos];
		}
	}
	return ret;
}
