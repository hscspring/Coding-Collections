#include<stdio.h>

int main()
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[5];
    // printf("*p=%d\n", *p);
    // int *p = &a[0];
    // int *p = a; 

    if ( a==&a[0] ) { printf("yam1\n"); }
    if ( p == &a[0] ) { printf("yam2\n"); }
    if ( *p == a[0] ) { printf("yam3\n"); }
    if ( p[0] == a[0] ) { printf("yam4\n"); }
    if ( p == a[0] ) { printf("yam5\n"); }

    printf("p=%p\n", p);
    printf("a=%p\n", a);
    

    printf("a[0]=%d\n", a[0]);
    printf("a[1]=%d\n", a[1]);
    printf("a[2]=%d\n", a[2]);
    printf("a[3]=%d\n", a[3]);
    printf("a[7]=%d\n", a[7]);
    // printf("a[-1]=%d\n", a[-1]);
    // printf("a[-2]=%d\n", a[-2]);
    // printf("a[-3]=%d\n", a[-3]);
    // printf("a[-4]=%d\n", a[-4]);
    // printf("a[-5]=%d\n", a[-5]);

    printf("p[0]=%d\n", p[0]);
    printf("p[1]=%d\n", p[1]);
    printf("p[2]=%d\n", p[2]);
    printf("p[3]=%d\n", p[3]);
    printf("p[7]=%d\n", p[7]);

    printf("p[-1]=%d\n", p[-1]);
    printf("p[-2]=%d\n", p[-2]);
    printf("p[-3]=%d\n", p[-3]);
    printf("p[-4]=%d\n", p[-4]);
    printf("p[-5]=%d\n", p[-5]);

    return 0;
}
