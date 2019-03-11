/*

字符串比对（10 分）
题目内容：

题目说起来很简单，你会读到两个字符串，每个字符串占据一行，每个字符串的长度均小于 10000 字符，而且第一个字符串的长度小于第二个字符串的。你的程序要找出第一个字符串在第二个字符串中出现的位置，输出这些位置，如果找不到，则输出 - 1。



注意，第一个字符的位置是 0。



注意，第一个字符串在第二个字符串中的位置可能不止一处。



注意，字符串中可能含有空格。



注意，两个字符串的长度一定大于 0。



输入格式:

两个字符串，一行一个。



输出格式：

第一个字符串在第二个字符串中出现的位置，按照从小到到的顺序排列，每个数字后面有一个空格。

如果在第二个字符串中找不到第一个字符串，则输出 - 1。



输入样例：

abba

ababbba abbabbabbabbaacc



输出样例：

8 11 14 17

时间限制：500ms 内存限制：32000kb

*/



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