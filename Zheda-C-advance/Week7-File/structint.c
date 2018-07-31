#include <stdio.h>

struct U0 {
	unsigned int leading: 3; // 占了几位
	unsigned int FLAG1: 1;
	unsigned int FLAG2: 1;
	int trailing: 27;
};

void prtBin(unsigned int number);
int main(int argc, char const *argv[])
{
	struct U0 uu;
	uu.leading = 2; // 赋值
	uu.FLAG1 = 0;
	uu.FLAG2 = 1;
	uu.trailing = 0;
	printf("sizeof(uu)=%lu\n", sizeof(uu));
	prtBin(*(int*)&uu);
	
	return 0;
}

void prtBin(unsigned int number)
{
	unsigned mask = 1u << 31;
	for (; mask; mask >>= 1) {
		printf("%d", number & mask ? 1:0);
	}
	printf("\n");
}