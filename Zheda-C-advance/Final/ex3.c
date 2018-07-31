#include <stdio.h>

// int main()
// {
// 	int y, z, w;
// 	static int x;
// 	printf("x=%d\n", x);
// 	printf("y=%d\n", y);
// 	printf("z=%d\n", z);
// 	printf("w=%d\n", w);
// 	return 0;
// }

int x,y,z,w;

void p(int *y, int x)
{	
    static int w;
    printf("w=%d\n", w);
    printf("*y=%d\n", *y);
    printf("x=%d\n", x);
    *y++;
    x++;
    printf("after x++, x=%d\n", x);
    printf("*--y=%d\n", *--y);
    w = x+*--y;
    printf("%d#%d#%d#%d#",x,*y,z,w);
}
int main(void)
{	
    int x, y, z, w;
    x=y=z=w=1;
    // printf("%d\n", x);
    do{
        static int x;
        // printf("%d\n", x);
        p(&x, y);
        printf("%d#%d#%d#%d#",x,y,z,w);
    } while(0);
    return 0;
}