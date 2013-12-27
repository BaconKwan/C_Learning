#include <stdio.h>

int max(float x, float y);

void main(){
	float a, b;
	int c;
	scanf("%f,%f", &a, &b);
	c = max(a,b);
	printf("Max is %d\n", c);
}

int max(float x, float y){
	float z;
	z = x > y? x : y;
	return(z);
}
