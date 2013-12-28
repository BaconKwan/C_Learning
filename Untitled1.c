#include <stdio.h>
#include <malloc.h>

int main(void){
	int* p = (int*)malloc(sizeof(int) * 10);
	int i;
	for(i = 0; i < 10; i++)
		p[i] = i;
	for(i = 9; i >=0; i--)
		printf("%d\n", p[i]);

	p = realloc(p, sizeof(int) * 5);
	for(i = 0; i < 5; i++)
		p[i] = i * 2;
	for(i = 39; i >=0; i--)
		printf("%d\n", p[i]);

	return 0;
}
