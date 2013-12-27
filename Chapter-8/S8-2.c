#include <stdio.h>

int max(int x, int y);

void main(){
	int a, b, c;
	scanf("%d,%d", &a, &b);
	c = max(a, b);
	printf("Max is %d", c);
}

int max(int x, int y){
	int z;
	z = x > y ? x : y;
	return(z);
}
