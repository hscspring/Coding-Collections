#include <stdio.h>
#include <string.h>


char* mycpy1(char* dst, const char* src)
{
	int idx = 0;
	while (src[idx] != '\0') { // while (src[idx])
		dst[idx] = src[idx];
		idx++;	
	}
	dst[idx] = src[idx]; // or '\0'
	return dst;
}

char* mycpy2(char* dst, const char* src)
{	
	char* ret = dst;
	while (*src) {
		*dst++ = *src++;
	}
	*dst = '\0';
	return ret;
}

char* mycpy3(char* dst, const char* src)
{	
	char* ret = dst;
	while (*dst++ = *src++) 
		;
	*dst = '\0';
	return ret;
}


int main(int argc, char const *argv[])
{	
	char s1[] = "abcf";
	char s2[] = "zxy";
	// strcpy(s1, s2);
	// mycpy1(s1, s2);
	// mycpy2(s1, s2);
	mycpy3(s1, s2);
	printf("res:%s\n", s1);
	printf("sizeof res: %lu\n", sizeof(s1));
	printf("sizeof res: %lu\n", strlen(s1));
	for (int i=0; i<sizeof(s1)/sizeof(s1[0]); i++) {
		printf("%d:%c\n", i,s1[i]);
	}
    return 0;
}
