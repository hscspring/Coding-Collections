#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
		printf("stack is empty");
		return ERROR;
	} else {
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

int main()
{	
	Stack s1 = CreateStack();
	for(int i=0; i<10; i++) {
		Push(s1, char2float('('));
	}
    for(int j=0; j<10; j++) {
        // printf("%f\n", Pop(s1));
        printf("%c\n", float2char(Pop(s1)));
        // printf("%c\n", (int)Pop(s1));
    }
    printf("%c\n", -8+'0');
    printf("%f\n", char2float('('));
}

