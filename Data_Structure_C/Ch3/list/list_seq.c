#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10
#define ERROR NULL

typedef struct Lnode *SeqList;
struct Lnode {
	int data[MAXSIZE];
	int last;
};

// init
SeqList InitSeqList() {
	SeqList L;
	L = (SeqList)malloc(sizeof(struct Lnode));
	L->last = -1;
	return L;
}

// find
int Find(SeqList L, int x) {
	int i = 0;
	while(i<=L->last && L->data[i] != x) 
		i++;
	if (i>L->last) {
		printf("SeqList isn't contain the element.\n"); 
		return ERROR;
	} else {
		return i;
	}
}

// insert
bool Insert(SeqList L, int x, int position) {
	int i;
	if(L->last==MAXSIZE-1) {
		printf("SeqList is full.");
		return false;
	}
	if(position<0 || position>L->last+1) {
		printf("position is illegal.\n");
		return false;
	}
	for(i=L->last; i>=position; i--) {
		L->data[i+1] = L->data[i];
	}
	L->data[position] = x;
	L->last++;
	return true;
}

// delete

bool Delete(SeqList L, int position) {
	int i;
	if(position<0 || position>L->last) {
		printf("location is illegal.\n");
		return false;
	}
	for(i=position+1; i<=L->last; i++) {
		L->data[i-1] = L->data[i];
	}
	L->last--;
	return true;
}

/* #######other operations####### */

// partition
void Partition(SeqList L) {
	int i,j,x,y;
	x = L->data[0];
	for(i=1; i<=L->last; i++) {
		if(L->data[i] < x) {
			y = L->data[i];
			for(j=i-1; j>=0; j--)
				L->data[j+1] = L->data[j];
			L->data[0] = y;
		}
	}
}

// merge
SeqList Merge(SeqList L1, SeqList L2) {
	int i=0, j=0, k=0;
	SeqList L;
	L = InitSeqList();
	while(i<=L1->last && j<=L2->last) {
		if(L1->data[i] < L2->data[j])
			L->data[k++] = L1->data[i++];
		else
			L->data[k++] = L2->data[j++];
	}
	while(i<=L1->last)
		L->data[k++] = L1->data[i++];
	while(j<=L2->last)
		L->data[k++] = L2->data[j++];
	L->last = k-1;
	return L;
}

// compare
int Compare(SeqList L1, SeqList L2) {
	int i=0, j, m, n;
	m = L1->last+1;
	n = L2->last+1;
	while(L1->data[i]==L2->data[i])
		i++;
	for(j=i; j<=L1->last; j++)
		L1->data[j-i] = L1->data[j];
	L1->last = j-i-1;
	for(j=i; j<=L2->last; j++)
		L2->data[j-i] = L2->data[j];
	L2->last = j-i-1;
	if(m==n) return 0;
	else if((L1->last==-1 && L2->last>-1) || 
		(L1->last>-1 && L2->last>-1 && L1->data[0]<L2->data[0])) 
		return -1;
	else return 1;
}


int main() {
	SeqList L;
	L = InitSeqList();

	int i;
	i = Find(L, 3);
	printf("before insert, find x=3 at location i: %d\n", i);
	
	Insert(L, 4, 0);
	Insert(L, 3, 1);
	i = Find(L, 3);
	printf("after insert, find x=3 at location i: %d\n", i);
	
	Delete(L, 0);
	i = Find(L, 3);
	printf("after delete, find x=3 at location i: %d\n", i);

	Insert(L, 2, 1);
	Insert(L, 18, 2);
	Insert(L, -1, 3);
	Insert(L, -2, 4);
	Insert(L, 0, 5);
	Insert(L, -5, 6);
	Insert(L, 8, 7);
	Insert(L, 1, 8);
	Insert(L, -7, 9);

	// partition
	{	
		printf("\nbefore partition.\n");
		for(int k=0; k<=sizeof(L->data)/sizeof(L->data[0]); k++)
			printf("%d ", L->data[k]);
		printf("\n");
	}

	Partition(L);

	{	
		printf("after partition.\n");
		for(int k=0; k<=sizeof(L->data)/sizeof(L->data[0]); k++)
			printf("%d ", L->data[k]);
		printf("\n");
	}

	// merge
	SeqList L1, L2;
	L1 = InitSeqList();
	Insert(L1, -20, 0);
	Insert(L1, 0, 1);
	Insert(L1, 20, 2);
	L2 = InitSeqList();
	for(int q=0; q<5; q++) {
		Insert(L2, q+1, q);
	}

	{	
		printf("\nL1: \n");
		for(int p=0; p<MAXSIZE; p++) 
			printf("%d ", L1->data[p]);
		printf("\nL2: \n");
		for(int q=0; q<MAXSIZE; q++) 
			printf("%d ", L2->data[q]);
	}

	SeqList LM;
	LM = Merge(L1, L2);
	{	
		printf("\nL1 L2 Merge: \n");
		for(int q=0; q<MAXSIZE; q++) 
			printf("%d ", LM->data[q]);
	}

	// compare
	SeqList A, B;
	A = InitSeqList();
	Insert(A, 1, 0);
	Insert(A, 2, 1);
	Insert(A, 2, 2);
	Insert(A, 3, 3);
	Insert(A, 5, 4);
	Insert(A, 1, 5);
	B = InitSeqList();
	Insert(B, 1, 0);
	Insert(B, 2, 1);
	Insert(B, 2, 2);
	Insert(B, 3, 3);
	Insert(B, 2, 4);
	Insert(B, 1, 5);
	Insert(B, 1, 6);
	Insert(B, 5, 7);
	int r = Compare(A, B);
	printf("\n\nCompare A and B: %d", r);
	switch(r) {
		case -1: printf("\nA<B\n"); break;
		case 0: printf("\nA=B\n"); break;
		case 1: printf("\nA>B\n"); break;
	}
}