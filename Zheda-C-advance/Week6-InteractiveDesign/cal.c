#include <stdio.h>

int plus(int a, int b)
{
    return a+b;
    // printf("%d ", a+b);
}
int minus(int a, int b)
{
    return a-b;
    // printf("%d ", a-b);
}
void cal(int (*f)(int, int))
{
    printf("%d ", (*f)(2, 3));
    // (*f)(2,3);
}
int main(void)
{
    cal(plus); // 5
    cal(minus); // -1
    return 0;
}