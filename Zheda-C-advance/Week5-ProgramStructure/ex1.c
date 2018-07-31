#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

int main()
{
	int i = 0;
	char s[100];
	strcpy(s, "abcd");
	putchar(TOUPPER(s[++i]));
	// int index = ++i;
	// printf("%d\n", index);
	// putchar(TOUPPER(s[index]));
}