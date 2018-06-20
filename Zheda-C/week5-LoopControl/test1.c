#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int sum = 0;
    int cntn = 0;
    int cntm = 0;
    int x = 2;

    while (cntn < n) {
        int i;
        int isPrime = 1;
        for (i = 2; i < x; i++) {
            if (x % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            // printf("%d ", x);
            cntn ++;
            cntm ++;
            if (cntm >= m) {
                sum += x;
            }

        }
        x ++;
    }
    printf("%d\n", sum);
    return 0;
}
