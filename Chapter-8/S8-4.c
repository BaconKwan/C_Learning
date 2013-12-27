#include <stdio.h>

int f(int a, int b);

void main(){
	int i = 2 , j = i, k = --i, p;
	p = f(j, k);
	printf("%d\n", p);
}

int f(int a, int b){
	int c;
	if (a > b)
		c = 1;
	else if (a == b)
		c = 0;
	else
		c = -1;
	return(c);
}
