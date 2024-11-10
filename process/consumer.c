#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define SIZE 4096

int main(void){
	char const *name = "OS";

	/* open the shared memory object. */
	int fd = shm_open(name, O_RDONLY, 0666);
	if (fd < 0){
		fprintf(stderr,
			"Error[%d]: %s.\nCould not create a new shared memory object with the name '%s'.\n",
			errno,
			strerror(errno),
			name);
		exit(EXIT_FAILURE);
	}
	/* memory map the shared memory object. */
	char *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
	if (ptr == MAP_FAILED){
		fprintf(stderr,
			"Error[%d]: %s.\nmmap operation failed.\n",
			errno,
			strerror(errno)
		);
		shm_unlink(name);
		exit(EXIT_FAILURE);
	}
	/* read from the shared memory object. */
	printf("%s\n", ptr);
	/* unmap a shared memory object. */
	munmap(ptr, SIZE);
	/* remove the shared memory object. */
	shm_unlink(name);
	exit(EXIT_SUCCESS);
}
