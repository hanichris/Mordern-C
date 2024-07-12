#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void){
	unsigned int N = 10;
	double largeA[N];
	double set[3] = {2.0, 1.0, -2.0};

	for(size_t i = 0; i < N; i++) largeA[i] = i * set[i % 3];

	size_t sign[2] = {0, 0};
	for(size_t i = 0; i < N; i++){
		sign[largeA[i] < 1.0] += 1;
	}
	printf("Count < 1.0: %zu\nCount >= 1.0: %zu\n", sign[1], sign[0]);
	return EXIT_SUCCESS;
}
