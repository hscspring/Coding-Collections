#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Polynode *PolyList;
struct Polynode {
	int coef;
	int exp;
	PolyList Next;
};

PolyList Create() {
	PolyList L, P, S;
	int c, e;
	L = (PolyList)malloc(sizeof(PolyList));
	L->Next = NULL;
	S = L;
	scanf("%d %d", &c, &e);
	while(c!=-1) {
		P = (PolyList)malloc(sizeof(PolyList));
		P->coef = c;
		P->exp = e;
		S->Next = P;
		S = P; // similar to tail insert(list_link Create2, 3), S slide to next
		scanf("%d %d", &c, &e);
	}
	S->Next = NULL;
	return L;
}

void AddPoly(PolyList A, PolyList B) {
	PolyList S, P, Q;
	int sum;
	P = A->Next;
	Q = B->Next;
	S = A; // remember that S is the silder(tail)
	free(B);
	while (P&&Q) {
		if (P->exp < Q->exp) {
			S->Next = P;
			S = P;
			P = P->Next;
		}
		else if (P->exp > Q->exp) {
			S->Next = Q;
			S = Q;
			Q = Q->Next;
		}
		else {
			sum = P->coef + Q->coef;
			if (sum != 0) {
				P->coef = sum;
				S->Next = P;
				S = P;
				P = P->Next;
				Q = Q->Next;
			}
			else {
				P = P->Next;
				Q = Q->Next;
				S->Next = P;
				S = P;
			}
		}
	}
	if (P==NULL) P = Q;
	while (P) {
		S->Next = P;
		S = P;
		P = P->Next;
	}
}


int main() {
	PolyList A, B;
	A = Create();
	B = Create();
	AddPoly(A, B);
	{
		while(A->Next != NULL) {
			printf("%d*X^%d+ ", A->Next->coef, A->Next->exp);
			A = A->Next;
		}
	}
	return 0;
}

// 5 0 4 2 7 5 8 12 -1 -1
// 3 1 2 2 -7 5 -1 -1