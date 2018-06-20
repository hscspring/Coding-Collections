#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number;
    scanf("%d", &number);
    int index = 0;
    int result = 0;
    int digit;
    int binary = 1;
    while (number > 0) {
        digit = number%10;
        index ++;
        number /= 10;
        if ((digit+index)%2 == 0) {
            result += binary;
            binary *= 2;
        }
        else {
            binary *= 2;
        }
    }
    printf("%d\n", result);
    return 0;
}
