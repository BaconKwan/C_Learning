#include <stdio.h>

int large(int x, int y);

void main(){
	int a[10], b[10], i, n = 0, m = 0, k = 0;
	printf("enter array a:\n");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	printf("\n");
	printf("enter array b:\n");
	for (i = 0; i < 10; i++)
		scanf("%d", &b[i]);
	printf("\n");
	for (i = 0; i < 10; i++){
		if (large(a[i], b[i]) == 1)
			n++;
		else if (large(a[i], b[i]) == 0)
			m++;
		else
			k++;
	}
	printf("a[i]>b[i]  %d  times\na[i]=b[i]  %d  times\na[i]<b[i]  %d  times\n", n, m, k);
	if (n > k)
		printf("array a is larger than array b\n");
	else if (n < k)
		printf("array a is smaller than array b\n");
	else
		printf("array is equal to array b\n");
}

int large(int x, int y){
	int flag;
	if (x > y)
		flag = 1;
	else if (x < y)
		flag = -1;
	else
		flag = 0;
	return(flag);
}
