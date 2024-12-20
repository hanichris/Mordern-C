#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct ua32 ua32;

struct ua32 {
	size_t length;
	uint32_t data[];
};

int main(void) {
	size_t len = 32;
	size_t size = offsetof(ua32, data) + sizeof(uint32_t[len]);

	// Adjust if the size is too small.
	if (size < sizeof(ua32))
		size = sizeof(ua32);

	ua32* ap = calloc(size, 1);
	if (!ap) {
		fprintf(stderr, "Could not allocate %zu bytes for an object of type struct ua32.\n", size);
		return EXIT_FAILURE;
	}

	// Ensure consistency between the length member and the object size.
	ap->length = len;

	// Use the ap->data mostly like an array.
	for (size_t i = 0; i < ap->length; i++)
		printf("ap->data[%zu] is %u\n", i, ap->data[i]);
	putchar('\n');

	return EXIT_SUCCESS;
}
