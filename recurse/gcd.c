#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t gcd2(size_t a, size_t b){
	assert(a <= b);
	if(!a) return b;
	return gcd2(b % a, a);
}

size_t gcd(size_t a, size_t b){
	assert(a);
	assert(b);
	if(a < b) return gcd2(a, b);
	return gcd2(b, a);
}

int main(void){
	printf("%lu\n", gcd(5, 3));
	return EXIT_SUCCESS;
}
