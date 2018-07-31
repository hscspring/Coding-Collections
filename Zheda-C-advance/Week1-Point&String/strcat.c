#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* mycat1(char* dst, const char* src)
{
	int lendst = strlen(dst);
	int lensrc = strlen(src);
	int idx = 0;
	while ( idx < lensrc ) {
		dst[lendst+idx] = *src++;
		idx++;
	}
	dst[lendst+idx] = '\0';
	return dst;
}

char* mycat2(char* dst, const char* src)
{
	int idx = 0;
	int len = strlen(dst);
	while ( idx < strlen(src) ) {
		dst[idx+len] = src[idx];
		idx++;
	}
	dst[idx+len] = '\0';
	return dst;
}

int main(int argc, char const *argv[])
{
	char str1[] = "Hello";
	char str2[] = "World.";
	// strcat(str1, str2);
	// printf("strcat=%s\n", str1);
	mycat1(str1, str2);
	printf("mycat=%s\n", str1);
    return 0;
}
