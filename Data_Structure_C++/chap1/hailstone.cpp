#include <stdio.h>

int hailstone(int n)
{
    int length = 1;
    while (1 < n) { n % 2 ? n = 3 * n + 1 : n /= 2; length++; }
    return length;
}

int main()
{
    int num_len = hailstone(42);
    printf("%d\n", num_len);
    return 0;
}
