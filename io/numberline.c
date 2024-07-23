/**
 * @file: text.c
 * @author: hanichris
 *
 * A program that reads a series of lines with numbers from
 * `stdin` and writes these same numbers in a normalised way
 * to `stdout` as comma separated hexadecimal numbers.
 * 
 * The program spilts the job into three different tasks.
 * 	1 => `fgetline` to read a line of text.
 * 	2 => `numberline` to split such a line into a series of numbers
 * 		 of type `size_t`. The core of the program lies here. The
 * 		 functionality is split into two parts which perform different
 * 		 tasks. One performs the task of interpreting the line, while
 * 		 the other is just a wrapper around the first and verifies the
 * 		 prerequisites for the first.
 * 	3 => `fprintnumbers` to print them.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


size_t*
numberline(size_t size, char const lbuf[restrict size], size_t* restrict np, int base);
char*
fgetline(size_t size, char s[restrict size], FILE*restrict stream);

int main(void){
	char lbuf[256];
	for (;;) {
		if (fgetline(sizeof lbuf, lbuf, stdin)) {
			size_t n;
			size_t* nums = numberline(strlen(lbuf) + 1, lbuf, &n, 0);
			int ret = fprintnumbers(stdout, "%#zX", ",\t", n, nums);
			if (ret < 0) return EXIT_FAILURE;
			free(nums);
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
}

static
size_t numberline_inner(char const*restrict act, size_t numb[restrict], int base) {
	size_t n = 0;
	for (char* next = 0; act[0]; act = next) {
		numb[n] = strtoull(act, &next, base);
		if (act == next) break;
		++n;
	}
	return n;
}


/**
 * interpret string `lbuf` as a sequence of numbers represented with base. The
 * caller is responsible for freeing the memory allocated for the array by calling
 * free().
 * 
 * @param[in] lbuf string.
 * @param[in] np if non-null, stores the count of numbers.
 * @param[in] base value from 0 - 36, with the same interpretation
 * as strtoul.
 * @return Returns a newly allocated array of numbers as found in `lbuf`.
 */
size_t*
numberline(size_t size, char const lbuf[restrict size], size_t* restrict np, int base) {
	size_t* ret = 0;
	size_t n = 0;
	// Check for validity of the string first.
	if (memchr(lbuf, 0, size)) {
		/**
		 * The maximum number of integers encoded.
		 * To see that this may be as much look at the sequence
		 * 08 08 08 08 ... and suppose that base is 0.
		*/
		ret = malloc(sizeof(size_t[1+(2*size)/3]));
		n = numberline_inner(lbuf, ret, base);

		/* supposes shrinking the array always succeeds. */
		size_t len = n ? n : 1;
		ret = realloc(ret, sizeof(size_t[len]));
	}
	if (np) *np = n;
	return ret;
}

/**
 * read one text line of at most size - 1 bytes. The '\n' character is replaced
 * by 0.
 * 
 * @param[out] s buffer to store the line of text.
 * @param[in] stream stream to read from.
 * @return Returns `s` if an entire line was read successfully. Otherwise, 0 is
 * returned and `s` contains a maximal partial line that could be read. `s` is
 * null terminated.
 */
char*
fgetline(size_t size, char s[restrict size], FILE*restrict stream) {
	/** 
	 * ensures the string is null terminated by enforcing it to
	 * be an empty string.
	 */
	s[0] = 0;
	char* ret = fgets(s, size, stream);
	if (ret) {
		char* pos = strchr(s, '\n');
		if (pos) *pos = 0;
		else ret = 0;
	}
	return ret;
}

/**
 * print a series of numbers `nums` in buf, using printf format `form`,
 * separated by `sep` characters and terminated with a newline character.
 * 
 * @pre `tot` and `buf` are big enough. `form` is a format suitable to print
 * size_t
 * 
 * @return Returns the number of characers printed to `buf`.
 */
static int sprintnumbers(size_t tot, char buf[restrict tot],
						 char const form[restrict static 1],
						 char const sep[restrict static 1],
						 size_t len, size_t nums[restrict len]) {
	char* p = buf; /* next position in the buffer. */
	size_t const seplen = strlen(sep);
	if (len) {
		size_t i = 0;
		for (;;) {
			p += sprintf(p, form, nums[i]);
			++i;
			if (i >= len) break;
			memcpy(p, sep, seplen);
			p += seplen;
		}
	}
	memcpy(p, "\n", 2);
	return (p - buf) + 1;
}