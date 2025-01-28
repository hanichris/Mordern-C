#include <math.h>
#if __GNUC__ > 4 && __GNUC__ <=14
# pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

#include "queue.h"

[[deprecated("implementation")]]
queue* queue_init(queue *q, unsigned cap) {
	if (q) {
		q->cap = cap;
	}
	return q;
}

[[deprecated("implementation")]]
static
size_t queue_getpos(queue const q[static 1], unsigned pos) {
	if (q->cap) {
		pos += q->start;
		pos %= q->cap;
	}
	return pos;
}

[[deprecated("implementation")]]
static
float* queue_element(queue const* q, unsigned pos) {
	float* ret = nullptr;
	if (q) {
		if (pos < q->cap) {
			pos = queue_getpos(q, pos);
			ret = (float*)&q->ar[pos];
		}
	}
	return ret;
}

[[deprecated("implementation")]]
queue* queue_enqueue(queue *q, float val) {
	if (q) {
		float* pos = queue_element(q, q->len);
		if (pos) {
			*pos = val;
			++q->len;
		}
	}
	return q;
}

[[deprecated("implementation")]]
float queue_dequeue(queue *q) {
	float ret = NAN;
	if (q && q->len) {
		float* pos = queue_element(q, 0);
		if (pos) ret = *pos;
		++q->start;
		--q->len;
	}
	return ret;
}

[[deprecated("implementation")]]
unsigned queue_getcount(queue const* q) {
	return q ? q->len : 0;
}

[[deprecated("implementation")]]
void queue_fput(queue const* q, FILE *s){
	if (q) {
		unsigned count = queue_getcount(q);
		fprintf(s, "%p+%u (%u+%u): ", (void*)q->ar, q->cap, q->start, count);
		for (unsigned i = 0; i < count; i++) {
			float* pos = queue_element(q, i);
			if (!pos) unreachable();
			fprintf(s, "\t%g", *pos);
		}
		putchar('\n');
		return;
	}
	fprintf(s, "Invalid queue\n");
}
