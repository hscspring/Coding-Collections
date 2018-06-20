#include <stdio.h>

int main()
{
    int i=0, j = 0, m = 0, n = 0;
    int len[1000];
    char c;
    while (c != '.')
    {
        scanf("%c", &c);
        if (c != ' ' && c != '.') 
        {
            n++;
            m = 0;
        }
        else
        {   
            if (m < 1)
            {
                len[j] = n;
                j++;
            }
            m += 1;
            n = 0;
        }
    }
    for (i=0; i<j; i++)
    {   
        printf("%d ", len[i]);
    }
    printf("\n");
    return 0;
}