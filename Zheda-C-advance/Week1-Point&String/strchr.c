#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	char s[] = "Hello";
	char *p = strchr(s, 'l');
	
	// 第一段：获得 l 前面的
	char c = *p;
	*p = '\0';
	char *t1 = (char*)malloc(strlen(s)+1);
	strcpy(t1, s); // 此时的 s 即为：he
	*p = c; // 把原来位置的东西给写回去
	printf("%s\n", t1);
	
	// 第二段：获得 l 后面的
	char *t2 = (char*)malloc(strlen(p)+1);
	strcpy(t2, p); // 将 p 所指的东西拷到 t，此时的 p 为 llo
	printf("%s\n", t2);
	p = strchr(p+1, 'l'); // 获得第二个 l 之后的，此时的 p 为 lo
	printf("%s\n", p); // llo，返回第一个 l 指向的指针，指向那个字符及后面的字符串

	free(t1);
	free(t2);
	return 0;
}