/*
摘自网上
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100] = "";
    char str1[] = "END";
    char str2[] = "$GPRMC";
    int jiaoyan1, jiaoyan3;
    char jiaoyan2[3];
    int jiaoyan4;
    int i, j, len;
    int hh, mm, ss;
    do{ 
        // fgets 获得的内容，strlen 会在本来的长度上加 1
        fgets(str, 101, stdin);
        if (strncmp(str, str2, 6) == 0)
            {
                for (jiaoyan1 = str[1], i = 2; str[i] != '*'; i++)
                    jiaoyan1 = jiaoyan1^str[i];
                
                jiaoyan3 = jiaoyan1 % 65536;

                len = strlen(str);
                printf("%d\n", len);

                for (i = len - 3, j = 0; j < 3; i++, j++)
                {	
                    printf("%d ", i);
                    printf("\n");
                	jiaoyan2[j] = str[i];
                    printf("%c ", str[i]);
                }

                sscanf(jiaoyan2, "%x", &jiaoyan4);
                if (jiaoyan3 == jiaoyan4)
                {
                    sscanf(str, "$GPRMC,%2d %2d %2d", &hh, &mm, &ss);
                }
             }
        } while (strncmp(str, str1, 3) != 0);
        hh = hh + 8;
        if (hh>= 24)
            hh = hh - 24;
        printf("%02d:%02d:%02d", hh, mm, ss);
        return 0;
}

