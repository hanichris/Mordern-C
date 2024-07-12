#include <limits.h>
#include <stdio.h>

enum corvid{ magpie, raven, jay, chough, corvid_num, };
#define FLOCK_MAGPIE (1U << magpie)
#define FLOCK_RAVEN (1U << raven)
#define FLOCK_JAY (1U << jay)
#define FLOCK_CHOUGH (1U << chough)
#define FLOCK_EMPTY 0U
#define FLOCK_FULL ((1U << corvid_num) - 1)


int main(void){
	for(signed i = INT_MAX - 10; i > 0; ++i)
		printf("%d ", i);
	printf("\n");
	return 0;
}	
