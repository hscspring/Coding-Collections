#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    int bw = a/100;
    int sw = a/10%10;
    int gw = a%10;
    int need = gw * 100 + sw * 10 + bw;
    printf("%d\n", need);
}
