#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

[[maybe_unused]]static
void matrix_multiply(
		size_t n,
		uint32_t const A[static n * n],
		uint32_t const B[static n * n],
		uint32_t C[static n * n]
) {
	for (unsigned i = 0; i < n; i++)
		for (unsigned j = 0; j < n; j++)
			for (unsigned k = 0; k < n; k++)
				C[n * i + j] += A[n * i + k] * B[n * j + k];
}

int main(void) {

	constexpr unsigned row = 5000;
	constexpr unsigned col = 5000;

	//uint32_t C[row * col] = { };
	//uint32_t A[row * col] = { };
	//uint32_t B[row * col] = { };
	uint32_t* C = calloc(row * col, sizeof(uint32_t));
	if (!C) {
		fprintf(stderr, "Could not allocate uint32_t[%u] bytes of memory.\n", row * col);
		return 1;
	}
	uint32_t* A = calloc(row * col, sizeof(uint32_t));
	if (!A) {
		fprintf(stderr, "Could not allocate uint32_t[%u] bytes of memory.\n", row * col);
		return 1;
	}
	uint32_t* B = calloc(row * col, sizeof(uint32_t));
	if (!B) {
		fprintf(stderr, "Could not allocate uint32_t[%u] bytes of memory.\n", row * col);
		return 1;
	}
	for (unsigned i = 0; i < row; i++) {
		for (unsigned j = 0; j < col; j++) {
			A[col * i + j] = arc4random() % (UCHAR_MAX + 1);
			B[row * j + i] = arc4random() % (UCHAR_MAX + 1);
		}
	}

	/*printf("Matrix A:\n");
	for (unsigned i = 0; i < row; i++) {
		for (unsigned j = 0; j < col; j++) {
			printf("%.3u ", A[col * i + j]);
		}
		putchar('\n');
	}
	fflush(stdout);

	printf("\nMatrix B:\n");
	for (unsigned i = 0; i < row; i++) {
		for (unsigned j = 0; j < col; j++) {
			printf("%.3u ", B[row * j + i]);
		}
		putchar('\n');
	}
	fflush(stdout);*/

	matrix_multiply(row, A, B, C);

	/*printf("\nComputation: C = C + A*B\n");
	for (unsigned i = 0; i < row; i++) {
		for (unsigned j = 0; j < col; j++) {
			printf("%u ", C[col * i + j]);
		}
		putchar('\n');
	}*/
	free(A);
	free(B);
	free(C);
	printf("FIN!!!\n");

	return 0;
}
