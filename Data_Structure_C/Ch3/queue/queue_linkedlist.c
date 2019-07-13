#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR 404

typedef struct Node *PtrToNode;
struct Node {
    int data;
    struct Node *Next;
};
typedef struct QNode *Queue;
struct QNode {
    PtrToNode rear, front;
    int MaxSize;
};

Queue Create(int MaxSize) {
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    PtrToNode Pd = (PtrToNode)malloc(sizeof(struct Node));
    Pd->Next = NULL;
    Q->front = Pd;
    Q->rear = Pd;
    Q->MaxSize = MaxSize;
    return Q;
}

bool isEmpty(Queue Q) {
    return Q->rear == Q->front;
}

bool Enqueue(Queue Q, int x) {
    PtrToNode P = (PtrToNode)malloc(sizeof(struct Node));
    P->data = x;
    P->Next = NULL;
    Q->rear->Next = P;
    Q->rear = P;
    return true;
}

int Dequeue(Queue Q) {
    if (isEmpty(Q)) {
        printf("queue is empty.\n");
        return ERROR;
    } else {
        PtrToNode FrontCell = (PtrToNode)malloc(sizeof(struct Node));
        FrontCell = Q->front->Next;
        Q->front->Next = FrontCell->Next;
        int x = FrontCell->data;
        free(FrontCell);
        // 只有一个元素时需要移动 rear 指针，否则不需要
        if (Q->front->Next == NULL) {
            Q->rear = Q->front;
        }
        return x;
    }
}


int main() {
    Queue q1 = Create(10);
    int ise = isEmpty(q1);
    printf("Is Empty? %d\n", ise);
    for (int i=0; i<10; i++) {
        Enqueue(q1, i+1);
    }
    // for (int j=0; j<10; j++) {
    //     printf("%d\n", q1->front->Next->data);
    //     q1->front = q1->front->Next;
    // }
    int x = Dequeue(q1);
    printf("x=%d\n", x);
}

