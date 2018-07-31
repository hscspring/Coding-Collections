#include<stdio.h>

int main()
{
    int a[] = {1,2,3,4,5,};
    int *p = a;
    int *q = &a[5];
    printf("q=%p\n", q);
    printf("*q=%d\n", *q);
    printf("%ld\n", q-p);
    return 0;
}
