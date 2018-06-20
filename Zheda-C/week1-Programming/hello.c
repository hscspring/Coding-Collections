#include <stdio.h>

int main()
{
    int price = 0;
    printf("input: ");
    scanf("%d", &price);
    int change = 100 - price;
    printf("back %d Yuan.\n", change);
    return 0;
}
