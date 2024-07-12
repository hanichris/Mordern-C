#include "circular.h"


/**
 * hidden implementation of the circular buffer type.
 * The position inside the `tab` is computed modulo `max_len`.
 */
struct circular {
	size_t start;		/**< Position of element 0. */
	size_t len;		/**< Number of elements stored. */
	size_t max_len;		/**< Maximum capacity */
	double* tab;		/**< Array holding the data */
};


circular* circular_init(circular* c, size_t max_len){
	if(c){
		if (max_len){
			*c = (circular){
				.max_len = max_len,
				.tab = malloc(sizeof(double[max_len])),
			};
		// Allocation failed.
		if (!c->tab) c->max_len = 0;
		} else {
			*c = (circular){ 0 };
		}
	}
	return c;
}

void circular_destroy(circular* c){
	if (c){
		free(c->tab);
		circular_init(c, 0);
	}
}

static size_t circular_getpos(circular* c, size_t pos){
	pos += c->start;
	pos %= c->max_len;
	return pos;
}

double* circular_element(circular* c, size_t pos){
	double* ret = 0;
	if (c){
		if (pos < c->max_len){
			pos = circular_getpos(c, pos);
			ret = &c->tab[pos];
		}
	}
	return ret;
}

circular* circular_new(size_t len){
	circular* c = malloc(sizeof(*c));
	if (c) c = circular_init(c, len);
	return c;
}

void circular_delete(circular* c){
	circular_destroy(c);
	free(c);
}

circular* circular_append(circular* c, double value){
	if (c){
		if (c->len + 1 <= c->max_len){
			c->tab[(c->start + c->len) % c->max_len] = value;
			c->len++;
		} else return 0;
	}
	return c;
}

double circular_pop(circular* c){
	double value = 0.0;
	if (c && c->len){
		value = c->tab[c->start];
		c->start = (c->start + 1) % c->max_len;
		c->len--;
	}
	return value;
}

size_t circular_getlength(circular* c){
	return c->len;
}
