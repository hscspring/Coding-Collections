#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct PolyNode *Polynomial;
struct PolyNode {
    int coef;
    int exp;
    Polynomial Next;
};

void Attach(int c, int e, Polynomial *Tail) {
	Polynomial L;
	L = (Polynomial)malloc(sizeof(struct PolyNode));
	L->coef = c;
	L->exp = e;
	L->Next = NULL;
	(*Tail)->Next = L;
	*Tail = L;
}

Polynomial ReadPoly() {
	Polynomial P, Tail;
	int n, coef, exp;
	scanf("%d", &n);
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	// P->Next = NULL;
	Tail = P;
	while (n--) {
		scanf("%d %d", &coef, &exp);
		Attach(coef, exp, &Tail);
	}
	Tail->Next = NULL;
	// 将首部的空节点删除
	// Tmp = P;
	// P = P->Next;
	// free(Tmp);
	return P;
}

void PrintPoly(Polynomial P) {
	int flag = 0;
	if (!P->Next) {
		printf("0 0\n");
		return;
	}
	while (P->Next) {
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d %d", P->Next->coef, P->Next->exp);
		P = P->Next;
	}
	printf("\n");
}

Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial P, Tail, t1, t2;
	t1 = P1; t2 = P2;
	int sum;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	Tail = P;
	// 因为第一个节点是空的，所以这里都用 ->Next 指向实际的第一个节点
	while (t1->Next && t2->Next) {
		if (t1->Next->exp == t2->Next->exp) {
			sum = t1->Next->coef + t2->Next->coef;
			if (sum) Attach(sum, t1->Next->exp, &Tail);
			t1 = t1->Next;
			t2 = t2->Next;
		} else if (t1->Next->exp > t2->Next->exp) {
			Attach(t1->Next->coef, t1->Next->exp, &Tail);
			t1 = t1->Next;
		} else {
			Attach(t2->Next->coef, t2->Next->exp, &Tail);
			t2 = t2->Next;
		}
	}
	while (t1->Next) {
		Attach(t1->Next->coef, t1->Next->exp, &Tail);
		t1 = t1->Next;
	}
	while (t2->Next) {
		Attach(t2->Next->coef, t2->Next->exp, &Tail);
		t2 = t2->Next;
	}
	Tail->Next = NULL;
	return P;
}

Polynomial Multiply1(Polynomial P1, Polynomial P2) {
	Polynomial P, Pt, PtTmp, Tail, t1, t2;
	if (!P1->Next || !P2->Next) return NULL;
	t1 = P1; t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Next = NULL;
	Tail = P;
	while (t1->Next) {
		Pt = (Polynomial)malloc(sizeof(struct PolyNode));
		PtTmp = Pt;
		while (t2->Next) {
			Attach(t1->Next->coef*t2->Next->coef, t1->Next->exp+t2->Next->exp, &PtTmp);
			t2 = t2->Next;
		}
		t2 = P2;
		t1 = t1->Next;
		P = Add(P, Pt);
	}	
	// Tail->Next = NULL;
	return P;
}

Polynomial Multiply2(Polynomial P1, Polynomial P2) {
	Polynomial P, t, Tail, t1, t2;
	int c, e;
	if (!P1->Next || !P2->Next) return NULL;
	t1 = P1; t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Next = NULL;
	Tail = P;
	while (t2->Next) {
		Attach(t1->Next->coef*t2->Next->coef, t1->Next->exp+t2->Next->exp, &Tail);
		t2 = t2->Next;
	}
	t1 = t1->Next;
	while (t1->Next) {
		t2 = P2;
		// 重新把 Tail 指向首部的下一个
		// 因为第一项肯定是最大的项数
		Tail = P->Next;
		while (t2->Next) {
			c = t1->Next->coef * t2->Next->coef;
			e = t1->Next->exp + t2->Next->exp;
			while (Tail->Next && Tail->Next->exp > e) 
				Tail = Tail->Next;
			if (Tail->Next && Tail->Next->exp == e) {
				if (Tail->Next->coef + c)
					Tail->Next->coef += c;
				else {
					t = Tail->Next;
					Tail->Next = t->Next;
					free(t);
				}
			} else {
				// 插入新节点
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->exp = e;
				t->Next = Tail->Next;
				Tail->Next = t;
				// Tail 后移
				Tail = Tail->Next;
			}
			t2 = t2->Next;
		}
		t1 = t1->Next;
	}
	// Tail->Next = NULL;
	return P;
}


int main() {
	Polynomial P1, P2, PM1, PM2, PA;
	P1 = ReadPoly();
	PrintPoly(P1);
	P2 = ReadPoly();
	PrintPoly(P2);
	PM1 = Multiply1(P1, P2);
	PrintPoly(PM1);
	PM2 = Multiply2(P1, P2);
	PrintPoly(PM2);
	PA = Add(P1, P2);
	PrintPoly(PA);
	return 0;
}