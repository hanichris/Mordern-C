#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#define SIZE 10

typedef struct
{
	uint32_t id;
	uint32_t amount;
} item;

int main(void)
{
	item *buffer = mmap(0, SIZE*sizeof(item), PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
	if (buffer == MAP_FAILED)
	{
		fprintf(stderr,
			"ERROR[%d]: %s.\nmmap operation failed.\n",
			errno,
			strerror(errno)
		);
		exit(EXIT_FAILURE);
	}
	int in = 0;
	int out = 0;

	pid_t pid = fork();
	if (pid < 0)
	{
		fprintf(stderr,
			"ERROR[%d]: %s.\nCould not create a child process.\n",
			errno,
			strerror(errno)
		);
		munmap(buffer, SIZE*sizeof(item));
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		item* c_cur = buffer;
		while (true)
		{
			while(in == out)
				;
			item consumed = c_cur[out];
			out = (out + 1) % SIZE;
			printf("Consuming item with id '%d'\n", consumed.id);
		}
		exit(10);
	} else {
		item *cur = buffer;
		int idx = 0;
		while (true)
		{
			while (((in + 1) % SIZE) == out)
				;
			printf("[%d] Adding item to the buffer at slot [%d]\n", idx + 1, in);
			cur[in] = (item){ .id=2234, .amount=4000 };
			in = (in + 1) % SIZE;
			idx++;
			if(idx == 15) break;
		}
		int status = 0;
		pid_t pid_1 = wait(&status);
		printf("Child process [%d] completed with a status value of %d\n", pid_1, status);
	}
	exit(EXIT_SUCCESS);
}
