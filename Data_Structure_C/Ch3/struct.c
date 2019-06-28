#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
} p1, p2, p5, *p3;

typedef struct point *pp;



typedef int Position;
struct LNode {
    int Data[10];
    Position Last;
};
typedef struct LNode *List;


typedef struct LNode2 *PtrToLnode;
struct LNode2 {
    int data;
    PtrToLnode next;
};

typedef struct Node {
    int data;
    struct Node *next;
} Lnode3, *LinkList;

 
int main() {

	struct point pl;
	pl=(struct point){5,10};
	p1.x = 1;
	p1.y = 2;
	printf("pl.x, pl.y: %d %d\n", pl.x, pl.y);
	printf("p1.x, p1.y: %d %d\n", p1.x, p1.y);
	printf("p3: %p\n", p3);
	
	p3 = &p2;
	p3->x = 3;
	p3->y = 4;
	printf("p3.x, p3.y: %d %d\n", (*p3).x, (*p3).y);
	printf("hello\n");

	pp p4;
	p4 = &p5;
	(*p4).x = 10;
	(*p4).y = 11;
	printf("p4: %p \n", p4);
	printf("p4.x, p4.y: %d %d\n", p4->x, p4->y);

	pp p6;
	p6 = (pp)malloc(sizeof(struct point));
	printf("p6: %p\n", p6);
	p6->x = 20;
	p6->y = 21;

	struct point origin, *ppp;
	ppp = malloc(sizeof(struct point));
	ppp->x = 30;
	ppp->y = 31;
	printf("ppp.x, ppp.y: %d %d\n", ppp->x, ppp->y);

	struct point origin2, *ppp2;
	ppp2 = &origin2;
	ppp2->x = 40;
	ppp2->y = 41;
	printf("ppp2.x, ppp2.y: %d %d\n", ppp2->x, ppp2->y);

	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;

	// struct p *p1;
	// p1->x = 7;
	// printf("%d\n", p1->x);

}