#include <stdio.h>

void f(int i)
{
    printf("in f(), %d\n", i);
}

void g(int i)
{
    printf("in g(), %d\n", i);
}

void k(int i)
{
    printf("in k(), %d\n", i);
}

int print(int (*f)(int))
{
    return (*f)(0);
}

int main(void)
{
    int i = 0;
    scanf("%d", &i);
    // ver1.0
    // if (i == 0) { f(0); }
    // else if (i == 1) { g(0); }
    // else if (i == 2) { k(0); }
    // ver2.0
    // switch(i)
    // {
    //     case 0: f(0); break;
    //     case 1: g(0); break;
    //     case 2: k(0); break;
    // }
    // ver3.0
    // void (*fa[])(int) = {f, g, k}; // 定义了一个 叫 fa 的函数指针数组，每一项都是一个函数指针
    // if (i>=0 && i<sizeof(fa)/sizeof(fa[0])) {
    //     (*fa[i])(0);
    // }
    // ver4.0
    print(f);
    print(g);
    print(k);
    return 0;
}