#include <stdio.h>
#include <string.h>

int main()
{   
    char s1[10000];
    char s2[10000];
    fgets(s1, 10000, stdin);
    fgets(s2, 10000, stdin);
    s1[strlen(s1)-1]='\0';
    char *p = strstr(s2, s1);
    if (p) {
        do { printf("%lu ", strlen(s2) - strlen(p)); }
        while (p = strstr(p+1, s1));
    } 
    else { printf("-1"); }
    return 0;
}


// 第二版
// int main()
// {   
//     char s1[10000];
//     char s2[10000];
//     fgets(s1, 10000, stdin);
//     fgets(s2, 10000, stdin);
//     s1[strlen(s1)-1]='\0';
    
//     int len = strlen(s2);
//     char *p = strstr(s2, s1);
//     if (p != NULL) {
//         printf("%lu ", len - strlen(p));
//         while (p = strstr(p+1, s1)) {
//             printf("%lu ", len - strlen(p));
//         }
//     }
//     else { printf("-1"); }
//     return 0;
// }



// 第一版
// int main()
// {   
//     // char *s=(char *)malloc(100*sizeof(char));
//     // scanf("%[^\n]", s1)
//     char s1[10000];
//     char s2[10000];
//     fgets(s1, 10000, stdin);
//     fgets(s2, 10000, stdin);
    
//     s1[strlen(s1)-1]='\0'; 
//     s2[strlen(s2)-1]='\0'; 

//     int len = strlen(s2);

//     char *p = strstr(s2, s1);
//     if (p == NULL) { printf("-1"); } 
//     else 
//     {   
//         printf("%lu ", len - strlen(p));
//         while (strstr(p+1, s1) != NULL) 
//         {
//             p = strstr(p+1, s1);
//             printf("%lu ", len - strlen(p));
//         }
//     }
    
//     return 0;
// }