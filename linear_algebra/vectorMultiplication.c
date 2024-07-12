#include <stdio.h>
#include <stdlib.h>


void vect2vec(unsigned aR, unsigned aC, int A[][aC],
	      unsigned bR, unsigned bC, int B[][bC]);

int main(void){
	int A[1][3] = {
		{1, 2, 3},
	};
	int B[3][1] = {
		{4},
		{5},
		{6},
	};
	vect2vec(1, 3, A, 3, 1, B);
	vect2vec(3, 1, B, 1, 3, A);
	return 0;
}

void vect2vec(unsigned aR, unsigned aC, int A[][aC],
	      unsigned bR, unsigned bC, int B[][bC]
)
{
	if(aC != bR){
		fprintf(stderr, "Error: col size %d != row size %d\n", aC, bR);
		return;
	}

	int C[aR][bC];

	for(unsigned i = 0; i < aR; ++i){
		for(unsigned j = 0; j < bC; ++j){
			C[i][j] = 0;
			for(unsigned k = 0; k < aC; ++k){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for(unsigned i = 0; i < aR; ++i){
		for(unsigned j = 0; j < bC; ++j)
			printf("%d ", C[i][j]);
		printf("\n");
	}

}
