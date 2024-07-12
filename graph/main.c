#include <stdbool.h>
#include "queue.h"

void bfs(unsigned r, unsigned c, bool [][c], unsigned start);

int main(void){
	bool A[5][5] = {
		{false, true, false, false, true},
		{true, false, true, true, true},
		{false, true, false, true, false},
		{false, true, true, false, true},
		{true, true, false, true, false},
	};
	bfs(5, 5, A, 3);

	return 0;
}

void bfs(unsigned r, unsigned c, bool A[][c], unsigned start){
	bool state[r];
	unsigned i = 0;
	
	for(unsigned i = 0; i < r; ++i){
		state[i] = false;	
	}
	
	state[start] = true;
	enqueue(start);
	while((i = dequeue()) != 79){
		for(unsigned j = 0; j < c; ++j){
			if(A[i][j] == true && state[j] == false){
				state[j] = true;
				enqueue(j);
			}
		}
		state[i] = true;
	}
	for(unsigned i = 0; i < r; i++) printf("Index: %u visited ?: %d\n", i, state[i]);
}
