/*
From https://blog.csdn.net/yuluows/article/details/7657944
*/

/*计算整数表达式的值
 *表达式必须以#结束
 *表达式中可以出现多位数字，
 *表达式中可以出现空格
 *运算符包括+,-,*,/,(,)
 *运算结果可以是多位整数，并以整数的形式返回
 */
typedef int SElemType;      /*放入堆栈的元素的类型*/
#include <ctype.h>
#include "stack_s.c"
/*判断输入的某个字符是否是运算符
 *c表示输入的字符
 *op数组中存放系统能识别的运算符
 */
Status in(char c,char op[]){
    char *p;
    p=op;
    while(*p != '\0'){
        if(c == *p)
            return TRUE;
        p++;
    }
    return FALSE;
}
/*比较两个运算符的优先级
 *a，b中存放待比较的运算符
 *'>'表示a>b
 *'0'表示不可能出现的比较
 */
char Precede(char a, char b){
    int i,j;
    char pre[][7]={         
    /*运算符之间的优先级制作成一张表格*/
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','0','>','>'},
        {'<','<','<','<','<','0','='}};
    switch(a){
        case '+': i=0; break;
        case '-': i=1; break;
        case '*': i=2; break;
        case '/': i=3; break;
        case '(': i=4; break;
        case ')': i=5; break;
        case '#': i=6; break;
    }
    switch(b){
        case '+': j=0; break;
        case '-': j=1; break;
        case '*': j=2; break;
        case '/': j=3; break;
        case '(': j=4; break;
        case ')': j=5; break;
        case '#': j=6; break;
    }
    return pre[i][j];
}
/*进行实际的运算
 *a，b中分别以整数的形式存放两个待运算的操作数
 *theta中存放代表操作符的字符
 *结果以整数的形式返回
 */
int Operate(int a, char theta, int b){
    int i,j,result;
    i=a;
    j=b;

    switch(theta)   {
        case '+': result = i + j; break;
        case '-': result = i - j; break;
        case '*': result = i * j; break;
        case '/': result = i / j; break;
    }
    return result;
}
/*从输入缓冲区中获得下一个整数或运算符，并通过n带回到主调函数
 *返回值为1表示获得的是运算符
 *返回值为0表示获得的是整形操作数
 */
int getNext(int *n){
    char c;
    *n=0;
    while((c=getchar())==' ');  /*跳过一个或多个空格*/
    if(!isdigit(c)){            /*通过函数判断如果字符不是数字，那么只能是运算符*/
        *n=c;
        return 1;
    }
    do    {                         /*能执行到该条语句，说明字符是数字，此处用循环获得连续的数字*/
        *n=*n*10+(c-'0');       /*把连续的数字字符转换成相对应的整数*/
        c=getchar();
    }    while(isdigit(c));         /*如果下一个字符是数字，进入下一轮循环*/
    ungetc(c,stdin);            /*新读入的字符不是数字，可能是运算符,为了不影响下次读入，把该字符放回到输入缓冲区*/
    return 0;
}

int EvaluateExpression(){

    int n;
    int flag;
    int c;
    char x,theta;
    int a,b;

    char OP[]="+-*/()#";
    SqStack  OPTR;
    SqStack  OPND;

    InitStack(&OPTR);      
    Push(&OPTR,'#');
    InitStack(&OPND);
    flag=getNext(&c);

    GetTop(OPTR, &x);
    while(c!='#' || x != '#')
    {
        if(flag == 0)
         {
                  Push(&OPND,c);
                  flag = getNext(&c);
             }        else
             {
            GetTop(OPTR, &x);
            switch(Precede(x, c))
            {
                case '<'://栈顶元素优先级低                    
                    Push(&OPTR,c);
                    flag = getNext(&c);
                    break;
                case '='://脱括号并接受下一字符 
                    Pop(&OPTR,&x);
                    flag = getNext(&c);
                    break;
                case '>': // 退栈并将运算结果入栈                                       
                    Pop(&OPTR, &theta);
                    Pop(&OPND,&b);
                    Pop(&OPND,&a);
                    Push(&OPND, Operate(a, theta, b));
                    break;
            }
        }
        GetTop(OPTR, &x);
    }
    GetTop(OPND, &c);
    return c;
}

void main(){
    int c;
    printf("Please input one expression:");
    c=EvaluateExpression();
    printf("Result=%d\n",c);
    // getch();
}






