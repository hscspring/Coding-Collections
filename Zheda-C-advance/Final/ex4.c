#include <stdio.h>
#include <string.h>

int main()
{	
    char a[20]="cehiknqtw";
    char *s="f", *p;
    int i, j;
    printf("add a=%p\n", a);
    printf("add p=%p\n", p);
    printf("add s=%p\n", s);
    // printf("*p=%d\n", *p);
    printf("*s=%c\n", *s);
    printf("*a=%c\n", *a);
    
    for(p=s; *p; p++) {
        j=0;
        while (*p>=a[j] && a[j]!='\0') {j++; printf("H");}

        for(i=strlen(a); i>=j; i--) a[i+1] = a[i];
        a[j]=*p;
    }
    printf("\n%s\n", a);
    return 0;
}