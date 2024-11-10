#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

#define SIZE 4096

int main(void)
{
	char const *name = "OS";
	char const *message_0 = "Hello";
	char const *message_1 = "World!";

	/* create a new shared memory object. */
	int fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	if (fd < 0)
	{
		fprintf(stderr,
			"Error[%d]: %s.\nCould not create a new shared memory object with the name '%s'.\n",
			errno,
			strerror(errno),
			name
		);
		exit(EXIT_FAILURE);
	}
	/* configure the size of the shared memory object. */
	if (ftruncate(fd, SIZE) < 0)
	{
		fprintf(stderr,
			"Error[%d]: %s.\nCould not truncate the file with id[%d] to '%d' bytes.\n",
			errno,
			strerror(errno),
			fd,
			SIZE
		);
		exit(EXIT_FAILURE);
	}
	/* memory map the shared memory object. */
	char *ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (ptr == MAP_FAILED)
	{
		fprintf(stderr,
			"Error[%d]: %s.\n'mmap' operation failed.\n",
			errno,
			strerror(errno)
		);
		exit(EXIT_FAILURE);
	}
	sprintf(ptr, "%s", message_0);
	ptr += strlen(message_0);
	sprintf(ptr, "_%s", message_1);
	ptr += strlen(message_1);
	ptr++;
	exit(EXIT_SUCCESS);
}
