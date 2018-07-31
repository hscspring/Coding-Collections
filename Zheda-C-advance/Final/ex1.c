#include <stdio.h>


// int main()
// {   
// 	int k;
// 	int a = 3; // [10] = {1,2,3};
// 	int *p=&a;

// 	printf("%p\n", p);
// 	printf("%p\n", &a);
// 	printf("%d\n", p[0]);
// 	printf("%d\n", p[1]); // 会变化
// 	printf("%d\n", p[22]); // 32766
// 	printf("%d\n", p[32]); // 32766
// 	printf("%d\n", *p);
// 	return 0;
// }


int main()
{   
	int k;
	int a[3] = {1,2,3};
	int *p = a;

	printf("p=%p\n", p);
	printf("&a=%p\n", &a);
	printf("a[0]=%d\n", a[0]);
	printf("a[4]=%d\n", a[4]);
	printf("p[0]=%d\n", p[0]);
	printf("p[1]=%d\n", p[1]); 
	printf("p[22]=%d\n", p[22]); 
	printf("*p=%d\n", *p);
	// printf("p++=%p\n", p++);
	printf("*p++=%d\n", *(p++));
	//printf("a++%d\n", a++);
	return 0;
}