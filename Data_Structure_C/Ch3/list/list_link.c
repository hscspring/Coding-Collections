#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR NULL

// define 1
// typedef struct Node {
// 	int data;
// 	struct Node *Next;
// } LNode, *LinkList;

// define2，prefer to this one
typedef struct LNode *PtrToLNode;
struct LNode {
    int data;
    PtrToLNode Next;
};
// we can define two meaningful datatype, but it's not a must
// typedef PtrToLNode Position;
// typedef PtrToLNode List;

// insert in head
PtrToLNode CreateLinkedList1() {
	PtrToLNode Head = NULL;
	PtrToLNode L; //or struct LNode *L;
	int x;
	scanf("%d", &x);
	while (x!=-1) {
		L = malloc(sizeof(PtrToLNode));
		L->data = x;
		L->Next = Head;
		Head = L;
		scanf("%d", &x);
	}
	return Head;
}

// insert in tail
PtrToLNode CreateLinkedList2() {
	PtrToLNode Head = NULL, Tail;
	PtrToLNode L; // struct LNode *L, *R=NULL;
	int x;
	scanf("%d", &x);
	while (x!=-1) {
		L = malloc(sizeof(PtrToLNode));
		L->data = x;
		if (Head==NULL)
			Head=L;
		else
			Tail->Next = L;
		Tail = L;
		scanf("%d", &x);
	}
	if (Tail!=NULL) {
		Tail->Next = NULL;
	}
	return Head;
}

// insert in tail with a head
PtrToLNode CreateLinkedList3() {
	PtrToLNode Head, Slide, L;
	int x;
	Head = (PtrToLNode)malloc(sizeof(struct LNode));
	// Head->Next = NULL; // comment or not
	Slide = Head;
	scanf("%d", &x);
	while (x!=-1) {
		// Slide->Next = malloc(sizeof(struct LNode));
		// Slide->Next->data = x;
		// Slide = Slide->Next;
		L = (PtrToLNode)malloc(sizeof(struct LNode));
		L->data = x;
		Slide->Next = L; //[IMPORTANT] when using Head, Head's address is changed, so only Slide, it's attress is head in first round
		Slide = L;
		scanf("%d", &x);
	}
	Slide->Next = NULL;
	return Head;
}


// link length
int Length(PtrToLNode L) {
	PtrToLNode P = L;
	int i = 0;
	while (P) {
		P = P->Next;
		i++;
	}
	return i-1;
}

// findKth
PtrToLNode FindKth(int k, PtrToLNode L) {
	PtrToLNode P = L;
	int i = 0;
	while(P!=NULL && i<k) {
		P = P->Next;
		i++;
	}
	if (i==k) 
		return P;
	else 
		return NULL;
}

// find X
PtrToLNode FindX(int x, PtrToLNode L) {
	PtrToLNode P = L;
	while(P!=NULL && P->data!=x)
		P = P->Next;
	return P;
}


// insert 
bool Insert(int x, int k, PtrToLNode L) {
	PtrToLNode Tmp, Pre;
	// we do not need this
	// only for CreateLinkedList1 and CreateLinkedList2
	// remember to modify bool -> PtrToLNode
    // if (k==1) {
    //     Tmp = (PtrToLNode)malloc(sizeof(struct LNode));
    //     Tmp->data = x;
    //     Tmp->Next = L;
    //     return Tmp;
    // }
	Pre = FindKth(k-1, L);
	if (Pre == NULL) {
		printf("param %d error\n", k);
		return false;
	}
	else {
		// insert
		Tmp = (PtrToLNode)malloc(sizeof(PtrToLNode));
		Tmp->data = x;
		Tmp->Next = Pre->Next;
		Pre->Next = Tmp;
		return true;
	}
}

// delete
bool Delete(int k, PtrToLNode L) {
	PtrToLNode Tmp, Pre;
	Pre = FindKth(k-1, L);
	if (Pre == NULL) {
		printf("node %d -1 do not exist\n", k);
		return false;
	}
	else if (Pre->Next == NULL) {
		printf("node %d do not exist\n", k);
		return false;
	}
	else {
		Tmp = Pre->Next;
		Pre->Next = Tmp->Next;
		free(Tmp);
		return true;
	}
}


// reverse
void Reverse(PtrToLNode L) {
	PtrToLNode P, Q;
	P = L->Next;
	L->Next = NULL;
	while (P) {
		Q = P;
		P = P->Next; //[IMPORTANT] can not move to last
		Q->Next = L->Next; //[IMPORTANT] Q->Next must be those have been inserted
		L->Next = Q; //[IMPORTANT] L->Next is always here
	}
}


// delete repeated
void Uniq(PtrToLNode L) {
	PtrToLNode P, Q, R;
	P = L->Next;
	// if (Length(L) <=1) {
	// 	return;
	// }
	if (P==NULL) {
		return;
	}
	else {
		while(P->Next) {
			Q = P;
			while (Q->Next) {
				if (Q->Next->data == P->data) {
					R = Q->Next;
					Q->Next = R->Next;
					free(R);
				} else {
					Q = Q->Next;
				}
			}
			P = P->Next;
		}
	}
}


// merge two increase list to one decrease list
PtrToLNode Merge(PtrToLNode A, PtrToLNode B) {
	PtrToLNode C, P, Q, R;
	P = A->Next;
	Q = B->Next;
	C = A;
	C->Next = NULL;
	while (P&&Q) {
		if (P->data < Q->data) {
			R = P;
			P = P->Next;
		} else {
			R = Q;
			Q = Q->Next;
		}
		R->Next = C->Next; //[IMPORTANT] C->Next is R's previous Node， so we can insert the node reverse
		C->Next = R; //[IMPORTANT] C is adding ONE NODE(R) each time
	}
	if (P==NULL) {
		P = Q;
	}
	while (P) {
		//[IMPORTANT] need reverse
		R = P;
		P = P->Next; //[IMPORTANT] can not move to last, bacause R is moving, it's P
		R->Next = C->Next; //[IMPORTANT] give those behind C to R->Next
		C->Next = R; //[IMPORTANT] R = R Node + those behind C
	}
	free(B);
	return C;
}


int main() {
	// ### Create ### //

	// PtrToLNode PL1;
	// PL1 = CreateLinkedList1();
	// {	
	// 	for (int i=0; i<4; i++) {
	// 		printf("%d ", PL1->data);
	// 		PL1 = PL1->Next;
	// 	}
	// }
	// printf("\n");
	// PtrToLNode PL2;
	// PL2 = CreateLinkedList2();
	// {	
	// 	printf("Print:\n");
	// 	while (PL2->Next != NULL) {
	// 		printf("%d ", PL2->data);
	// 		PL2 = PL2->Next;
	// 	}
	// 	printf("%d\n", PL2->data);
	// 	printf("\n");
	// }
	// printf("\n");
	PtrToLNode PL3;
	PL3 = CreateLinkedList3();
	printf("PL1 Done\n");
	// {	
	// 	printf("Print:\n");
	// 	for (int i=0; i<4; i++) {
	// 		printf("%d ", PL3->Next->data);
	// 		PL3 = PL3->Next;
	// 	}
	// }
	// printf("\n");

	// ### Length ### //
	// int len = Length(PL3);
	// printf("PL3's Length: %d\n", len);

	// ### Find Kth ### //
	// PtrToLNode KPL, XPL;
	// KPL = FindKth(3, PL3);
	// printf("the 3rd data is: %d \n", KPL->data);
	// XPL = FindX(2, PL3);
	// printf("2 is: %d \n", XPL->data);

	// ### Insert ### //

	// PL2
	// PtrToLNode IPL;
	// IPL = Insert(99, 1, PL2);

	// {	
	// 	printf("Print:\n");
	// 	while (IPL->Next != NULL) {
	// 		printf("%d ", IPL->data);
	// 		IPL = IPL->Next;
	// 	}
	// 	printf("%d\n", IPL->data);
	// 	printf("\n");
	// }

	// PL3
	// Insert(99, 1, PL3);
	// {
	// 	printf("Print:\n");
	// 	while (PL3->Next != NULL) {
	// 		printf("%d ", PL3->Next->data);
	// 		PL3= PL3->Next;
	// 	}
	// 	printf("\n");
	// }

	// ### Delete ### //

	// Delete(1, PL3);
	// {
	// 	printf("Print:\n");
	// 	while (PL3->Next != NULL) {
	// 		printf("%d ", PL3->Next->data);
	// 		PL3= PL3->Next;
	// 	}
	// 	printf("\n");
	// }

	// ### Reverse ### //
	// Reverse(PL3);
	// {
	// 	printf("Print:\n");
	// 	while (PL3->Next != NULL) {
	// 		printf("%d ", PL3->Next->data);
	// 		PL3= PL3->Next;
	// 	}
	// 	printf("\n");
	// }

	// ### Uniq ### //
	// Uniq(PL3);
	// {
	// 	printf("Print:\n");
	// 	while (PL3->Next != NULL) {
	// 		printf("%d ", PL3->Next->data);
	// 		PL3= PL3->Next;
	// 	}
	// 	printf("\n");
	// }

	// ### Merge ### //
	PtrToLNode PL4;
	PL4 = CreateLinkedList3();

	printf("PL2 done...\n");

	PtrToLNode PLC;
	PLC = Merge(PL3, PL4);

	printf("Merge Done...");
	{
		printf("Print:\n");
		while (PLC->Next != NULL) {
			printf("%d ", PLC->Next->data);
			PLC= PLC->Next;
		}
		printf("\n");
	}

	return 0;
}


