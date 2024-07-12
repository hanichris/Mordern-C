#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[argc + 1]){
	size_t len = strlen(argv[0]);
	char name[len + 1];

	memcpy(name, argv[0], len);
	name[len] = 0;
	if(!strcmp(name, argv[0])){
		printf("Program name \"%s\" successfully copied\n", name);
	} else{
		printf("Copying %s leads to a different string %s\n", argv[0], name);
	}
	return 0;
}
