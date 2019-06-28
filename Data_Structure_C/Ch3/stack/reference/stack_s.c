#include <stdio.h>

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW    -2

typedef int  Status;
#define STACK_INIT_SIZE  100
#define STACKINCREMENT   10

typedef struct{
    SElemType *base;
    SElemType *top;
    int      stacksize;
}SqStack;
//构造一个空栈
Status InitStack(SqStack *S){
    S->base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));

    if(!S->base)
        exit(OVERFLOW);
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return OK;
}
//判断是否为空栈
Status StackEmpty(SqStack S){
    if(S.top == S.base)
        return TRUE;
    else
        return FALSE;
}
//用e返回S的顶元素
Status GetTop(SqStack S, SElemType *e){
    if(S.top == S.base)
        return ERROR;
    *e = *(S.top-1);
    return OK;
}
//插入e为新的顶元素
Status Push(SqStack *S, SElemType e){
    if((S->top - S->base) >= S->stacksize){
        S->base = (
                    SElemType*)realloc(S->base,
                   (S->stacksize+STACKINCREMENT)*sizeof(SElemType)
                   );
        if(!S->base)
            exit(OVERFLOW);
        S->top = S->base +S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(S->top)=e;
    S->top++;
    return OK;
}
//删除S的顶元素，并用e返回其值
Status Pop(SqStack *S, SElemType *e){
    if(S->top == S->base)
        return ERROR;
    S->top--;
    *e = *(S->top);
    return OK;
}
//从栈底到栈顶依次对S的每个元素调用函数Visit（），一旦失败操作无效
Status ListTraverse(SqStack S,Status (*visit)(SElemType)){
    SElemType *p;
    p=S.base;
    for(p=S.base;p<S.top;p++)
        (*visit)(*p);

    return OK;
}
//输出元素e
Status output(SElemType e){
    printf("%d ",e);

    return OK;
}

