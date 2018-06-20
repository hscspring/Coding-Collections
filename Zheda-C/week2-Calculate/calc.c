#include <stdio.h>

int main()
{
    printf("a=%d\n", 6 + 5/4 -2);
    printf("b=%d\n", 2 + 2 *(2*2-2)%2/3);
    printf("c=%d\n", 10 + 9*((8+7)%6) + 5*4%3*2 + 3);
    printf("d=%d\n", 1 + 2 + (3+4) *((5*6%7/8)-9)*10);
    int a = 14;
    int t1 = a++;
    int t2 = ++a;
    printf("t1=%d, t2=%d\n", t1,t2);
    printf("a=%d\n", a);
}
