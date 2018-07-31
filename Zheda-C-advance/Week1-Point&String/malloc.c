#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number;
	int *a; //C99 之前
	int i;
	printf("input:");
	scanf("%d", &number);
	// int a[number]; //C99
	a = (int*)malloc(number*sizeof(int)); // C99 之前
	printf("%lu\n", sizeof(a));
	for (i=0; i<number; i++) {
		scanf("%d", &a[i]);
	}
	for ( i=number-1; i>=0; i--) {
		printf("%d ", a[i]);
	}
	free(a); // C99 之前
	return 0;
}
