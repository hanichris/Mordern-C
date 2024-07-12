#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

enum {buf_max = 32, };

int main(int argc, char* argv[argc + 1]){
	int ret = EXIT_FAILURE;
	char buf[buf_max] = {0};

	if(argc == 1){
		while(fgets(buf, buf_max, stdin))
			fputs(buf, stdout);
		ret = EXIT_SUCCESS;
	} else{
		for(int i = 1; i < argc; i++){
			FILE* instream = fopen(argv[i], "r");
			if(instream){
				while(fgets(buf, buf_max, instream))
					fputs(buf, stdout);
				fclose(instream);
				ret = EXIT_SUCCESS;
			} else {
			  fprintf(stderr, "Could not open %s: ", argv[i]);
			  perror(0);
			  errno = 0;
			}
		}
	}

	return ret;
}
