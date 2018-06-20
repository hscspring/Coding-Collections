#include <stdio.h>

int maxgy(int a, int b)
{	
	int t;
	while (b != 0) {
	    t = a%b;
	    a = b;
	    b = t;
	}
	return a;
}


int main()
{
	int x, y, t;
	scanf("%d/%d", &x, &y);
	t = maxgy(x,y);
	printf("%d/%d\n", x/t,y/t);
	return 0;
}
