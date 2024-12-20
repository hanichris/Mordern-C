#include "circular.h"
#if __GNUC__ > 4 && __GNUC__ <= 14
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif


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

[[deprecated("implementation")]]
circular* circular_append(circular *c, double value) {
	if (c) {
		if (c->len < c->cap) {
			c->tab[c->len] = value;
			c->len++;
		}
	}
	return c;
}

[[deprecated("implementation")]]
size_t circular_getlength(const circular *c) {
	if (c) {
		return c->len;
	}
	return 0;
}

[[deprecated("implementation")]]
double circular_pop(circular *c) {
	double val = 0.0;
	if (c && c->len > 0) {
		val = c->tab[c->start];
		c->start++;
		c->len--;
	}
	return val;
}

[[nodiscard("returned pointer replaces function argument.")]]
[[deprecated("implementation")]]
circular* circular_resize(circular *c, size_t nlen) {
	if (c) {
		size_t len = c->len;
		if (len > nlen) return nullptr;
		size_t olen = c->cap;
		if (nlen != olen) {
			size_t ostart = circular_getpos(c, 0);
			size_t nstart = ostart;
			[[maybe_unused]]double* otab = c->tab;
			double* ntab = nullptr;
			if (nlen > olen) {
				ntab = realloc(c->tab, sizeof(double[nlen]));
				if (!ntab) return nullptr;
				if (ostart + len > olen) {
					size_t ulen = olen - ostart;
					size_t llen = len - ulen;
					if (llen <= (nlen - olen)) {
						memcpy(ntab + olen, ntab, llen * (sizeof(double)));
					} else {
						nstart = nlen - ulen;
						memmove(ntab + nstart, ntab + ostart, ulen * sizeof(double));
					}
				}

			}

			*c = (circular) {
				.cap = nlen,
				.start = nstart,
				.len = len,
				.tab = ntab,
			};
		}

	}
	return c;
}
