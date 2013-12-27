#include <stdio.h>

int age(int n);

void main(){
	printf("%d\n", age(5));
}

int age(int n){
	int c;
	if (n == 1)
		c = 10;
	else
		c = age(n - 1) + 2;
	return(c);
}
