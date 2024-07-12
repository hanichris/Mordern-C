#include "queue.h"

unsigned queue[SIZE];
unsigned end = 0;
unsigned top = 0;

void enqueue(unsigned index){
	if(end == SIZE-1 || top > end){
		fprintf(stderr, "Error: Underflow\n");
		return;
	}
	queue[end++] = index;
}

unsigned dequeue(void){
	if(end == top){
		fprintf(stderr, "Error: Queue is empty\n");
		end = 0;
		top = 0;
		return 79;
	}
	return queue[top++];
}
