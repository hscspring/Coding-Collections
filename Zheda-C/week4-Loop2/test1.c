#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int jn = 0;
    int on = 0;
    int number;
    scanf("%d", &number);
    while (number != -1) {
        if (number%2 == 0) {
            on ++;
        }
        else {
            jn ++;
        }
        scanf("%d", &number);
    }
    printf("%d %d\n", jn, on);
    return 0;
}
