#include <stdio.h>

int main()
{
    int btc;
    int utc;
    scanf("%d", &btc);
    if (btc < 800) {
       utc = 2400 - 800 + btc;
    }
    else {
        utc = btc - 800;
    }
    printf("%d\n", utc);
}
