#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   
    int a,b;
    scanf("%d/%d", &a, &b);

    const int number = 200;
    int count[number];
    int i;
    for (i = 0; i < number; i++) {
        count[i]  = 0;
    }

    int cnt = 0;
    int remain;
    printf("0.");
    do {
        count[cnt] = (a*10)/b;
        printf("%d", count[cnt]);
        remain = (a*10)%b;
        a = remain;
        cnt ++;
    } while (remain != 0 && cnt < number);
    printf("\n");
}
