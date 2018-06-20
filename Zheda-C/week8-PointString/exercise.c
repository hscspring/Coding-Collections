#include <stdio.h>

// *a 原来为 a[]
void minmax(int *a, int len, int *max, int *min);

int main(void)
{
    int a[] = {1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55};
    int min, max;
    printf("minmax sizeof(a)=%lu\n", sizeof(a));
    printf("main a=%p\n", a);
    minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
    printf("a[0]=%d\n", a[0]);
    printf("main sizeof(a)=%lu\n", sizeof(a));
    printf("min=%d,max=%d\n", min, max);
    // min 是个变量 2；
    // 现在有一个指针 p 指向了 min 的地址
    // *p 表示指针 p 所指向的那个变量的值，所以应为 2
    // p[0] 是把 p 所指向的地方当做一个数组
    // int b[] --> int * const b;
    int *p = &min;
    printf("*p=%d\n", *p);
    printf("p[0]=%d\n", p[0]);
    printf("*a=%d\n", *a);
    printf("a[0]=%d\n", a[0]);

    return 0;
}

void minmax(int *a, int len, int *min, int *max)
{
	int i;
	printf("minmax sizeof(a)=%lu\n", sizeof(a));
	printf("minmax a=%p\n", a);
	a[0] = 1000;
	*min = *max = a[0];
	for ( i=1; i<len; i++) {
		if ( a[i] < *min ) {
			*min = a[i];
		}
		if ( a[i] > *max ) {
			*max = a[i];
		}
	}
}