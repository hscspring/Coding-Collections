#include<stdio.h>

int main()
{
	char ac[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
	char *p = ac;
	printf("p  =%p\n", p);
	printf("p+1=%p\n", p+1);
	printf("*(p+1)=%d\n", *(p+1));
	printf("*(p+2)=%d\n", *(p+2));

	int ai[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
	int *q = ai;
	printf("q  =%p\n", q);
	printf("q+1=%p\n", q+1);
	printf("*q=%d\n", *q);
	printf("*(q+1)=%d\n", *(q+1));
	printf("*(q+2)=%d\n", *(q+2));
	printf("*(q+3)=%d\n", *(q+3));
	printf("*(q+4)=%d\n", *(q+4));


	char *r = ai;
	printf("r  =%p\n", r);
	printf("r+1=%p\n", r+1);
	printf("*r=%d\n", *r);
	printf("*(r+1)=%d\n", *(r+1));
	printf("*(r+2)=%d\n", *(r+2));
	printf("*(r+3)=%d\n", *(r+3));
	printf("*(r+4)=%d\n", *(r+4));

    return 0;
}
