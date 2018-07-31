#include<stdio.h>


struct point
{
	int x;
	int y;
};

struct point* getStruct(struct point*);
void output(struct point); // 要的是值
void print(const struct point *p); // 要的结果不需要改变

int main(int argc, char const *argv[])
{
	struct point y = {0, 0};
	
	getStruct(&y);
	printf("cut\n");
	output(y);

	output(*getStruct(&y)); // output 要的是结构本身，用 * 取出函数返回的东西
	
	print(getStruct(&y));

	*getStruct(&y) = (struct point){1, 2}; // 这样也可以
}

struct point* getStruct(struct point *p)
{
	scanf("%d", &p->x); // 取得 p 所指的 x
	scanf("%d", &p->y);
	printf("%d, %d\n", p->x, p->y);
	return p;
}

void output(struct point p)
{
	printf("%d, %d\n", p.x, p.y);
}

// print 函数不需要修改
void print(const struct point *p)
{
	printf("%d, %d\n", p->x, p->y);
}