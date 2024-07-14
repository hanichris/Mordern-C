#include "circular.h"
#include <string.h>


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

void circular_setstartindex(circular* c, size_t start){
	if (c) c->start = start;
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

circular* circular_resize(circular* c, size_t nlen){
	if (c){
		size_t len = c->len;
		if (len > nlen) return 0;
		size_t olen = c->max_len;
		if (nlen != olen){
			size_t ostart = circular_getpos(c, 0);
			size_t nstart = ostart;
			double* otab = c->tab;
			double* ntab;
			if (nlen > olen){
				ntab = realloc(c->tab, sizeof(double[nlen]));
				if (!ntab) return 0;
				if (ostart + len > olen){
					size_t ulen = olen - ostart;
					size_t llen = len - ulen;
					if (llen <= (nlen - olen)){
						memcpy(ntab + olen, ntab, llen*sizeof(double));
					} else {
						nstart = nlen - ulen;
						memmove(ntab + nstart, ntab + ostart, ulen*sizeof(double));
					}
				}
			} else {
				if (ostart + len > olen){
					size_t ulen = olen - ostart;
					nstart = nlen - ulen;
					memmove(otab + nstart, otab + ostart, ulen*sizeof(double));
				}

				ntab = realloc(c->tab, sizeof(double[nlen]));
				if (!ntab) return 0;
				
			}
			*c = (circular){
				.max_len = nlen,
				.start = nstart,
				.len = len,
				.tab = ntab,
			};
		}
	}
	return c;
}

size_t circular_getmaxlength(circular* c){
	return c->max_len;
}

