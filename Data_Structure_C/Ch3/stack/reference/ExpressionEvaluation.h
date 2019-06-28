/* **************************
 * Head file of Expression Evaluation
 * *************************/
#ifndef EXPRESSION_EVALUATION_H
#define EXPRESSION_EVALUATION_H

#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILE 1

#define LEN 20 //栈的长度先定义为5,需要时可自行修改

typedef char StackElmt; //把char当作栈中元素的类型，实际中可以使用其它的类型或者自己定义一个元素类型
typedef struct _Stack{
    StackElmt *base;
    StackElmt *top;
    int size;
}Stack;

StackElmt STACK[LEN+1] = {0}; //顺序存储方式的栈,防止数组越界，最后一个位置不放元素

//声明函数原型，这里有入栈和出栈操的函数
int StackInit(Stack *s);
int StackDestroy(Stack *s);
int StackPrint(Stack *s);
int StackPush(Stack *s, StackElmt e);
int StackPop(Stack *s, StackElmt *e);

#endif /* EXPRESSION_EVALUATION_H */