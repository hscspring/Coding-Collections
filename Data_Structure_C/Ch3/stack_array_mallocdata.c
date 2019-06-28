#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR 404

typedef int Position;
struct SNode {
    int *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (int*)malloc(sizeof(int)); // (int*)malloc(MaxSize * sizeof(int));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool IsFull(Stack S)
{
    return (S->Top == S->MaxSize-1);
}

bool Push(Stack S, int X)
{
    if (IsFull(S)) {
        printf("堆栈满");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty(Stack S)
{
    return (S->Top == -1);
}

int Pop(Stack S)
{
    if (IsEmpty(S) ) {
        printf("堆栈空");
        return ERROR; /* ERROR 是 int 的特殊值，标志错误 */
    }
    else 
        return (S->Data[(S->Top)--] );
}

int main()
{	
	Stack s1 = CreateStack(10);
	for(int i=0; i<10; i++) {
		Push(s1, i);
	}
    for(int j=0; j<10; j++) {
        printf("%d\n", Pop(s1));
    }
}
