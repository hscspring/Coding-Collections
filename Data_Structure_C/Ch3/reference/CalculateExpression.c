#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h>             // 申请内存
#include <ctype.h>              // 内含isdigit()函数
#include <assert.h>             // 断言函数
#include <string.h>             // 内含字符串处理函数
#define STACK_INIT_SIZE 100     // 栈容量
#define STACK_INCREMENT 10      // 栈增量

typedef float DATATYPE;
typedef char SYMBOLTYPE;

typedef struct stack
{
    int *base;         // 基地址
    int *top;          // 栈顶指针
    int stackSize;          // 栈容量
}*Stack;

// 栈的初始化
Stack Init_Stack(Stack S)
{
    S=(Stack)malloc(sizeof(Stack));
    if(!S)
        exit(0);
    S->base = (int*)malloc(STACK_INIT_SIZE*sizeof(DATATYPE));
    if(!S->base)
        exit(0);
    S->top = S->base;
    S->stackSize = STACK_INIT_SIZE;
    return S;
}

// 判栈空
int IsEmpty(Stack S)
{
    if (S->top == S->base)
    {
        return 1;
    } else
    {
        return 0;
    }
}

// 判栈满
int IsFull(Stack S)
{
    if (S->top - S->base == S->stackSize)
    {
        return 1;
    } else
    {
        return 0;
    }
}

// 操作数压栈
void Push(Stack S, DATATYPE e)
{
    assert(S);
    if (IsFull(S))
    {
        S->base = (int*)malloc((STACK_INIT_SIZE+STACK_INCREMENT)*sizeof(DATATYPE));
        if (!S->base)
            exit(0);        // 存储分配失败
        S->top = S->base + S->stackSize;
        S->stackSize += STACK_INCREMENT;
    }
    *S->top++ = e;
}

// 运算符压栈
void PushSymbol(Stack S, SYMBOLTYPE e)
{
    assert(S);
    if (IsFull(S))
    {
        S->base = (int*)malloc((STACK_INIT_SIZE+STACK_INCREMENT)*sizeof(DATATYPE));
        if (!S->base)
            exit(0);        // 存储分配失败
        S->top = S->base + S->stackSize;
        S->stackSize += STACK_INCREMENT;
    }
    *S->top++ = e;
}

// 操作数弹栈
DATATYPE Pop(Stack S)
{
    assert(S);
    if (S->top == S->base)
        return 0;              // 空栈弹出0保证部分负数的正确运算
    else
    {
        return *--S->top;     // *--S->top就是*(--S->top)
    }
}

// 运算符弹栈
SYMBOLTYPE PopSymbol(Stack S)
{
    assert(S);
    if (S->top == S->base)
        return 0;
    else
    {
        return *--S->top;
    }
}

// 栈的销毁
void DestroyStack(Stack S) {
      free(S->base);
      free(S);
}

// 运算符优先级表
char Priority[7][7] =
{           // '+' '-' '*' '/' '(' ')' '#'          行row（左边的）是栈顶运算符，列col（上边的）是入栈运算符
   {/*'+'*/'>','>','<','<','<','>','>'},
    {/*'-'*/'>','>','<','<','<','>','>'},
    {/*'*'*/'>','>','>','>','<','>','>'},
    {/*'/'*/'>','>','>','>','<','>','>'},
    {/*'('*/'<','<','<','<','<','=','0'},
    {/*')'*/'>','>','>','>','0','>','>'},
   {/*'#'*/'<','<','<','<','<','0','='}
};

// 确定运算符所在的行数或列数
int Operator(char c)
{
    switch(c)
    {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '(': return 4;
        case ')': return 5;
        case '#': return 6;
        default:  return -1;
    }
}

// 计算弹出的两个操作数与弹出栈顶运算符的值
float Calculation(float a, char op, float b)
{
    switch(op)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        default:  return -1;
    }
}

// 表达式求值函数
float CalculatingExpression(char *s)
{
    int i;
    strcat(s, "#");                 // 为表达式s串接"#"
    Stack OPND=NULL;
    OPND = Init_Stack(OPND);        // 创建操作数栈
    Stack OPTR=NULL;
    OPTR = Init_Stack(OPTR);        // 创建运算符栈
    PushSymbol(OPTR, '#');          //"#"压栈作为运算符栈的栈底元素
    for (i=0; i<strlen(s); ++i)
    {
        while(s[i]==' ')            // while循环跳过空格
            ++i;
        if (isdigit(s[i]))          // 判断是否是数字
        {
            int j=i;
            ++i;
            while(isdigit(s[i]))        // 确定是几位数
            {
                ++i;
            }
            if (!isdigit(s[i]))     // 将while循环里因判断是否是数字多加的i值减去
                --i;
            char str[10]="";
            for (; j<=i; ++j)           // 将字符串数组下标j到i的数字字符转换为字符串
            {
                char c[2] = {s[j]};
                strcat(str, c);
            }
            float operand = atof(str);  // 将字符串转换为浮点数
            Push(OPND, operand);        // 浮点数压入操作数栈
        }
        else {
            int row = Operator(*(OPTR->top-1)), col = Operator(s[i]);       // 确定栈顶运算符的行数，入栈运算符的列数
            switch(Priority[row][col])              // 确定优先级
            {
                case '<': PushSymbol(OPTR, s[i]); break;
                case '>': Push(OPND, Calculation(Pop(OPND), PopSymbol(OPTR), Pop(OPND))); --i; break;       
                             //Push()参数里右边的Pop先执行；--i是为了下次继续对当前入栈运算符s[i]进行判断
                case '=': PopSymbol(OPTR); break;
                default:  printf("输入错误，请检查数字之间是否有空格，表达式是否正确！\n");
                          DestroyStack(OPTR);
                          DestroyStack(OPND);
                          return -4294967296;           // 运行到这一步，说明表达式错误，直接返回调用函数（主函数）
            }
        }
    }
    DestroyStack(OPTR);
    return Pop(OPND);       // 运行到这一步，说明表达式正确，弹出操作数栈的值即为运算结果
}

int main()
{
    char s[100];
    printf("请输入要计算的表达式：\n");
    gets(s);
    printf("表达式 %s 的值为：\n", s);
    printf("%1.2f", CalculatingExpression(s));

    return 0;
}


