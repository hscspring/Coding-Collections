#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR 404

typedef struct Node *Queue;
struct Node {
    int * data;
    int front, rear;
    int MaxSize;
};

Queue Create(int MaxSize) {
    Queue Q = (Queue)malloc(sizeof(struct Node));
    Q->data = (int*)malloc(sizeof(int));
    Q->front = Q->rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool isFull(Queue Q) {
    return (Q->rear + 1) % Q->MaxSize == Q->front;
}

bool isEmpty(Queue Q) {
    return Q->rear == Q->front;
}

bool Enqueue(Queue Q, int x) {
    if (isFull(Q)) {
        printf("queue is full.\n");
        return false;
    } else {
        Q->rear = (Q->rear + 1) % Q->MaxSize;
        Q->data[Q->rear] = x;
        return true;
    }
}

int Dequeue(Queue Q) {
    if (isEmpty(Q)) {
        printf("queue is empty.\n");
        return ERROR;
    } else {
        Q->front = (Q->front + 1) % Q->MaxSize;
        return Q->data[Q->front];
    }
}


int main() {
    Queue q1 = Create(10);
    for (int i=0; i<9; i++) {
        Enqueue(q1, i);
    }
    for (int j=0; j<10; j++) {
        if (j==0) continue;
        printf("%d\n", q1->data[j]);
    }
    Dequeue(q1);
    int x = Dequeue(q1);
    printf("x=%d\n", x);
}

