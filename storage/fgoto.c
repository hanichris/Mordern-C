#include <stdio.h>

void fgoto(unsigned n){
	unsigned j = 0;
	unsigned* p = 0;
	unsigned* q;
AGAIN:
	if (p){
		printf("%u: p and q are %s, *p is: %u\n",
			j,
			(q == p) ? "equal": "unequal",
			*p);
	}
	q = p;
	p = &((unsigned){ j, });
	++j;
	if (j <= n) goto AGAIN;
}

int main(void){
	unsigned num = 5;
	fgoto(num);
	return 0;
}
