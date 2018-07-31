#include <stdio.h>


int main(int argc, char** argv)
{	
	printf("argc=%d\n", argc);
	printf("argv=%p\n", argv);
	printf("*argv=%s\n", *argv);
	printf("**argv=%c\n", **argv);

    while(**argv++!='a') printf("%s\n", *argv);;
    // printf("%s\n", *argv);
    return 0;
}