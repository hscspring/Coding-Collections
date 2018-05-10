#include<stdio.h>

int fib(int n)
{
    if (n==0)
        return 1;
    else if (n==1)
        return 2;
    else
        return fib(n-1) + fib(n-2);
}

int main()
{
    int cnt = fib(8);
    printf("%d\n", cnt);
    return 0;
}
