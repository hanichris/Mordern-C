#if !defined(queue_h)
#define queue_h

#include <stdio.h>

#define SIZE 64
void enqueue(unsigned);
unsigned dequeue(void);

extern unsigned queue[SIZE];

#endif
