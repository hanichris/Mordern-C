#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[argc + 1]) {
	size_t const len = strlen(argv[0]); // computes the length of the program name.
	// Initialised VLA, C23
	// Ensures the array is 0-terminated.
	char name[len + 1] = { };
	memcpy(name, argv[0], len);

	if (!strcmp(name, argv[0])) {
		printf("Program name, '%s' successfully copied.\n", name);
	} else {
		fprintf(stderr, "Copying '%s' leads to different string '%s'.\n", argv[0], name);
	}

	exit(EXIT_SUCCESS);
}
