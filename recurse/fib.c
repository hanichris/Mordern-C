#include <stdio.h>
#include <stdlib.h>

size_t fib(size_t n);

int main(int argc, char* argv[argc + 1]){
	char* endptr;
	size_t res = strtoul(argv[1], &endptr, 10);
	printf("%lu\n", fib(res));
	return EXIT_SUCCESS;
}

size_t fib(size_t n){
	if(n < 2)
		return 1;

	size_t first = 1;
	size_t second = 1;
	for(unsigned i = 2; i <= n ; ++i){
		size_t res = first + second;
		second = first;
		first = res;
	}
	return first;
}
