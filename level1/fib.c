#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * fib - naive implementation of the fibonacci sequence of numbers.
 * @n: The desired value of the fibonacci sequence to compute.
 * @Returns: the value of the fibonacci sequence of the element passed in.
 */
static size_t fib(size_t n) {
	if (n < 3) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

static size_t fibCacheRec(size_t n, size_t cache[static n]) {
	if (!cache[n - 1]) {
		cache[n - 1] = fibCacheRec(n - 1, cache) + fibCacheRec(n - 2, cache);
	}
	return cache[n - 1];
}

/**
 * fibCache - an improved implementation of the fibonacci algorithm with
 * a linear execution time in 'n'.
 * @n: The desired value of the fibonacci sequence to compute.
 * @Returns: the value of the fibonacci sequence of the element passed in.
 */
static size_t fibCache(size_t n) {
	if (n + 1 <= 3) return 1;
//#if __STDC_VERSION__ > 202311L
	size_t cache[n] = { };
//#else
	//size_t cache[n];
	//memset(cache, 0, n * sizeof(*cache));
//#endif
	cache[0] = 1;
	cache[1] = 1;
	return fibCacheRec(n, cache);
}

static void fib2rec(size_t n, size_t buf[static 2]) {
	if (n > 2) {
		size_t res = buf[0] + buf[1];
		buf[1] = buf[0];
		buf[0] = res;
		fib2rec(n - 1, buf);
	}
}

static void fib2iter(size_t n, size_t buf[static 2]) {
	if (n > 2) {
		for (unsigned i = 2; i < n; i++) {
			size_t res = buf[0] + buf[1];
			buf[1] = buf[0];
			buf[0] = res;
		}
	}
}

/**
 * fib2 - an improved implementation of the fibonacci algorithm that relies
 * on a constant-length array to compute the requested value.
 * @n: the desired value of the fibonacci sequence to compute.
 * @Returns: the value of the fibonacci sequence of the element passed in.
 */
static size_t fib2(size_t n) {
	size_t res[2] = {1, 1};
	fib2iter(n, res);
	return res[0];
}


int main(int argc, char* argv[argc]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <input_value>\n", argv[0]);
		return 1;
	}
	unsigned long num = strtoul(argv[1], nullptr, 10);
	size_t res = fib2(num);
	printf("fib(%zu): %zu\n", num, res);

	return 0;
}
