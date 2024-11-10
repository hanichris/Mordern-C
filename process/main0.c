/**
 * The system call fork() creates a new process in the UNIX / LINUX environment.
 * Both the parent and child processes continue their execution at the instruction after the
 * system call. The child process gets a copy of the parent's address space setting up a communication
 * channel between the two. The caveat with the call to fork() is that it returns a process id of 0
 * in the child process while also returning a non zero process id to the parent which is the child's
 * process id.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void) {
	pid_t pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork failed\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) { /* The child process exectues this portion of the instructions.*/
		printf("Child process is executing\n");
		execlp("/bin/ls", "ls", 0);
	}
	else { /* The parent process exectutes this portion of the instructions. */
		printf("Parent process executing\n");
		wait(0);
		printf("Child Complete\n");
	}
	exit(EXIT_SUCCESS);
}
