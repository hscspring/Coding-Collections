/* 
适合于表达式每个数字是个位数的四则混合运算。
因为使用了 getchar 一次获取一个单个的数。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ERROR 404

typedef struct SNode *Stack;

struct SNode {
	float Data;
	Stack Next;
};

Stack CreateStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

bool IsEmpty(Stack S) {
	return S->Next == NULL;
}

bool Push(Stack S, float X) {
	Stack TmpCell;
	TmpCell = (Stack)malloc(sizeof(struct SNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
}

float Pop(Stack S) {
	Stack FirstCell;
	float TopElem;
	if(IsEmpty(S)) {
		return (int)ERROR;
	} else {
		// S 有头结点
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
	}
}

float char2float(char a) {
	return a - '0';
}

char float2char(float a) {
	return a + '0';
}

float Operate(float i, char theta, float j) {
	float res;
	switch (theta) {
		case '+': res = i + j; break;
		case '-': res = i - j; break;
		case '*': res = i * j; break;
		case '/': res = i / j; break;
		case '^': res = pow(i, j); break;
	}
	return res;
}

bool isOp(char c) {
	char op[] = "+-*/^()";
	for (int i=0; i<sizeof(op)/sizeof(op[0]); i++) {
		if (op[i] == c) {
			return true;
		}
	}
	return false;
}

int PrecedeIn(char a) {
	int res;
	if (a == '+' || a == '-')
		res = 1;
	else if (a == '(')
		res = 0;
	else if (a == ')')
		res = -1;
	else if (a == '^')
		res = 3;
	else if (a == '#')
		res = -2;
	else
		res = 2;
	return res;
}

int PrecedeOut(char a) {
	int res;
	if (a == '+' || a == '-')
		res = 1;
	else if (a == '(')
		res = 4;
	else if (a == ')')
		res = -1;
	else if (a == '^')
		res = 4;
	else if (a == '#')
		res = -2;
	else
		res = 2;
	return res;
}

// a*(b+c)/d  ==> abc+*d/ 5*(1+3)/2# => 513+*2/
// 2*3+4/2# ==> 23*42/+#
// 2*(9+6/3-5)+4 ==> 2963/+5-*4+
// 2*(1+(2+3)*2+5*5)/9#

Stack Middle2Suffix() {
	Stack Suffix = CreateStack();
	Stack Expr = CreateStack();
	Stack Oper = CreateStack();
	char c, tmp;
	int pre1, pre2;
	c = getchar();
	while (c!='#') {
		if (IsEmpty(Oper)) {
			Push(Oper, char2float('#'));
		}
		// printf("\n\n======begin========");
		// printf("This is the c: %c\n", c);
		if (!isOp(c)) {
			// printf("EXPR1: %c\n", c);
			Push(Expr, char2float(c));
		} else {
			if (c == '(') {
				Push(Oper, char2float(c));
			} else if (c == ')') {
				tmp = float2char(Pop(Oper));
				//  && tmp !='#'
				while (tmp != '(') {
					// printf("EXPR2: %c\n", tmp);
					Push(Expr, char2float(tmp));
					tmp = float2char(Pop(Oper));
					// printf("LOOKLOOK: %c\n", tmp);
				}
			} else {
				tmp = float2char(Pop(Oper));
				// printf("POP OUT: %c\n", tmp);
				// 需要再 push 进去
				pre1 = PrecedeOut(c);
				pre2 = PrecedeIn(tmp);
				// printf("pre1, pre2: %d %d \n", pre1, pre2);
				if (pre1 > pre2) {
					// printf("LOOKLOOK2: %c\n", tmp);
					Push(Oper, char2float(tmp));
					Push(Oper, char2float(c));
				} else {
					while (pre1 <= pre2) {
						// printf("EXPR3: %c\n", tmp);
						Push(Expr, char2float(tmp));
						tmp = float2char(Pop(Oper));
						if (tmp == '(') {
							Push(Oper, char2float(tmp));
							break;
						}
						// printf("LOOKLOOK3: %c\n", tmp);
						pre2 = PrecedeIn(tmp);
						// printf("IN ==> pre1, pre2: %d %d \n", pre1, pre2);
					}
					Push(Oper, char2float(c));
				}
			}
		}
		c = getchar();
	}
	while (!IsEmpty(Oper)) {
		tmp = float2char(Pop(Oper));
		if (tmp != '#') {
			// printf("EXPR4: %c\n", tmp);
			Push(Expr, char2float(tmp));
		}
	}

	while (!IsEmpty(Expr)) {
		tmp = float2char(Pop(Expr));
		Push(Suffix, char2float(tmp));
	}

	return Suffix;
}

float EvaluateSuffix(Stack Expr) {
	Stack Nums = CreateStack();
	char c;
	float a, b, num;
	while (!IsEmpty(Expr))
	{
		c = float2char(Pop(Expr));
		if (!isOp(c)) {
			num = char2float(c);
			Push(Nums, num);
		} else {
			b = Pop(Nums);
			a = Pop(Nums);
			Push(Nums, Operate(a, c, b));
		}
	}
	return Pop(Nums);
}

float EvaluateSuffix2(char * expr) {
	Stack Nums = CreateStack();
	char c;
	float a, b, num;
	int i = 0;
	while (expr[i] != '#')
	{
		c = expr[i++];
		if (!isOp(c)) {
			num = char2float(c);
			Push(Nums, num);
		} else {
			b = Pop(Nums);
			a = Pop(Nums);
			Push(Nums, Operate(a, c, b));
		}
	}
	return Pop(Nums);
}


int main() {
	// char * expr = "64/3-42*+#";
	// char * expr1 = "23*42/+#";
	// char * expr2 = "513+*2/#";
	char * expr = "2123+2*+*2/#";

	Stack Expr = Middle2Suffix();
	float res = EvaluateSuffix(Expr);
	printf("RES: %f\n", res);
	
	// while (!IsEmpty(Expr)) {
	// 	printf("%c", float2char(Pop(Expr)));
	// 	printf("%c", float2char(Expr->Next->Data));
	// 	Expr = Expr->Next;
	// }

	printf("\n");
	return 0;
}

