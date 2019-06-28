/* **************************
 * Soure file of Expression Evaluation
 * *************************/

#include"ExpressionEvaluation.h"

//实现栈相关的函数，为了方便,放到了主函数所在的文件中，最好是单独建立实现函数的源文件
//初始化中栈
int StackInit(Stack *s) 
{
    if(NULL == s)
        return FAILE;

    s->top = s->base = &STACK[0];
    s->size = 0;
}

int StackDestroy(Stack *s)
{
    int i =0;

    if(NULL == s)
        return FAILE;

    while(i<LEN)
    {
        STACK[i] = 0;
        i++;
    }
    s->top = s->base = NULL;
    s->size = 0;
}

//输出栈中存放的元素
int StackPrint(Stack *s)
{
    int index = 0;

    if(NULL == s)
        return FAILE;

    if(s->size == 0)
    {
        printf("the Stack is empty,there is not any element \n");
        return FAILE;
    }

    while(index < (s->size))
    {
        printf("%d  ",*((s->base)+index) );
        index++;
    }

    printf("\n ");

    return SUCCESS;
}

//入栈函数,top指向栈顶,先把元素入栈,然后向栈顶移动一位
int StackPush(Stack *s, StackElmt e)
{
    if(NULL == s)
        return FAILE;

    if(s->size >= LEN)
    {
        printf("the Stack is full \n");
        return FAILE;
    }

    *(s->top) = e;
    (s->top)++;
    (s->size)++;

    return SUCCESS;
}

//出栈函数,top先向栈底移到一位，然后移出当前它所指向的元素
int StackPop(Stack *s, StackElmt *e)
{
    if(NULL == s)
        return FAILE;

    if(s->size == 0)
    {
        //printf("the Stack is empty \n");
        return FAILE;
    }

    (s->top)--;
    *e = *(s->top);
    (s->size)--;

    return SUCCESS;
}

int main()
{
    char ch = '\0';
    char str[2];
    char *a1= "1+(2-3)*3+5"; // 存放中缀表达式
    //char *a1="1+2+3*4";
    char a2[LEN]={'\0'}; // 存放后缀表达式
    Stack s;
    int i,j;
    int a,b;
    int res = 0;
    int stack[LEN] ={0};

    i = j = a = b = 0;
    StackInit(&s);

    while(*(a1+i) != '\0') //遍历中缀表达式
    {
        printf("%c",*(a1+i));

        if(*(a1+i) == '+' || *(a1+i) == '-')
        {
            if(s.size != 0)
            {
                while( s.size >= 0 && !StackPop(&s,&ch))
                {
                    *(a2+j) = ch;
                    ch = '\0';
                    j++;
                }
                StackPush( &s,*(a1+i) );
            }
            else
                StackPush(&s,*(a1+i));
        }
        else if( *(a1+i) == '*' || *(a1+i) == '/')
        {
            if(s.size != 0)
            {
                if(!StackPop(&s,&ch))
                {
                    if(ch == '+' || ch == '-')
                    {
                        StackPush(&s,ch);
                        StackPush( &s,*(a1+i) );
                    }
                    else
                    {
                        StackPush(&s,ch);
                        while( !StackPop(&s,&ch) && (ch == '*' || ch == '/') )
                        {
                            *(a2+j) = ch;
                            ch = '\0';
                            j++;
                        }
                        StackPush( &s,*(a1+i) );
                    }
                }
            }
            else
                StackPush(&s,*(a1+i));
        }
        else //从中缀表达式中读取的字符是数字，保存到数组中
        {
            *(a2+j) = *(a1+i);
            j++;
        }

        i++;
    }

    while( s.size >= 0 && !StackPop(&s,&ch)) //栈中还有运算符的话，需要全部取出，放到后缀表达式中
    {
        *(a2+j) = ch;
        ch = '\0';
        j++;
    }
    *(a2+j) = '\0';

    i=j=0;
    StackDestroy(&s);
    StackInit(&s);

    while(*(a2+i) != '\0') //遍历后缀表达式
    {
        if(*(a2+i) == '+')
        {
            j--;
            a = stack[j];
            j--;
            b = stack[j];

            stack[j]= a+b;
            j++;
        }
        else if(*(a2+i) == '-')
        {
            j--;
            a = stack[j];
            j--;
            b = stack[j];

            stack[j]= b-a;
            j++;
        }
        else if(*(a2+i) == '*')
        {
            j--;
            a = stack[j];
            j--;
            b = stack[j];

            stack[j]= a*b;
            j++;
        }
        else if(*(a2+i) == '/')
        {
            j--;
            a = stack[j];
            j--;
            b = stack[j];

            stack[j]= b/a;
            j++;
        }
        else
        {
            str[0] =*(a2+i);
            str[1] ='\0';
            stack[j]= atoi(str);
            j++;
        }

        i++;
    }
    res =stack[0];

    printf(" = %d ",res);
    printf("\n");
    return SUCCESS;
}