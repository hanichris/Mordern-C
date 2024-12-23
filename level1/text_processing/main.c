#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static
size_t numberline_inner(char const* restrict act, size_t numb[restrict static 1], int base) {
	size_t n = 0;
	for (char* next = nullptr; act[0]; act = next) {
		numb[n] = strtoull(act, &next, base);
		if (act == next) break;
		++n;
	}
	return n;
}

/**
 * numberline - interpret string `lbuf` as a sequence of numbers represented with `base`.
 * @lbuf: supposed to be a string.
 * @np: if non-null, the count of numbers is stored in `*np`.
 * @base: value from 0 to 36, with the same interpretation as for `strtoul` and similar
 * functions.
 * @Returns: a newly allocated array of numbers as found in `lbuf`.
 */
static
size_t* numberline(size_t size, char const lbuf[restrict static size], size_t* restrict np, int base ) {
	size_t* ret = nullptr;
	size_t n = 0;
	// Check for the string's validity.
	if (memchr(lbuf, 0, size)) {
		// Maximum number of integers to encode.
		ret = malloc(sizeof(size_t[1 + (2 * size) / 3]));
		if (!ret) return nullptr;
		n = numberline_inner(lbuf, ret, base);

		size_t len = n ? n : 1;
		size_t* ret2 = realloc(ret, sizeof(size_t[len]));
		if (ret2) ret = ret2;
	}

	if (np) *np = n;

	return ret;
}

/**
 * fgetline - reads one text line of at most `size - 1` bytes. The `\n` character is replaced by 0.
 * @Returns: s if an entire line was read successfully. Othewise 0 is returned and s contains a
 * maximal partial line that could be read. s is null terminated.
 */
static
char* fgetline(size_t size, char s[restrict size], FILE* restrict stream) {
	s[0] = 0;
	char* ret = fgets(s, size, stream);
	if (ret) {
		char* pos = strchr(ret, '\n');
		if (pos) *pos = 0;
		else ret = nullptr;
	}
	return ret;
}

int main(void) {
	char lbuf[256];
	for (;;) {
		if (fgetline(sizeof lbuf, lbuf, stdin)) {
			size_t n;
			size_t* nums = numberline(strlen(lbuf) + 1, lbuf, &n, 0);

			if (nums) {
				//int ret = fprintnumbers(stdout, "", "", n, nums);
				//if (ret < 0) return EXIT_FAILURE;
				for (size_t i = 0; i < n; i++)
					printf("%zu ", nums[i]);
				putchar('\n');
				free(nums);
			}
		} else {
			if (lbuf[0]) {
				for (;;) {
					int c = getc(stdin);
					if (c == EOF) return EXIT_FAILURE;
					if (c == '\n') {
						fprintf(stderr, "line too long: %s", lbuf);
						break;
					}
				}
			} else break;
		}
	}

	return 0;
}
