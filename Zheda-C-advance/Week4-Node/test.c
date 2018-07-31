#include "stdio.h"
#include "stdlib.h"

const int BLOCK_SIZE = 20;

typedef struct {
    int *array;
    int size;
} Array;

Array array_create(int init_size) {
    Array a;
    a.array = (int*)malloc(sizeof(int)*init_size);
    a.size = init_size;
    return a;
}

void array_free(Array *a) {
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

void array_inflate(Array *a, int more_size) {
    int *p = (int*)malloc(sizeof(int)*(a->size+more_size));
    for (int i=0; i<a->size; i++) {
        p[i] = a->array[i];
    }
    free(a->array);
    a->array = p;
    a->size += more_size;
}

int* array_at(Array *a, int index) {
    if (index >= a->size) {
        array_inflate(a, (index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size);
    }
    return &(a->array[index]);
}


int main(int argc, char const *argv[]) {
    Array a = array_create(100);
    int number = 0;
    int cnt = 0;
    while (number != -1) {
        scanf("%d", &number);
        if (number != -1) {
            *array_at(&a, cnt++) = number;
        }
    }
    for (int i=cnt-1; i>=0; i--) {
        printf("%d ", a.array[i]);
    }
    array_free(&a);
    return 0;
}




// const int MAXN = 500;

// int main(int argc, const char* argv[]) {

//     int number;
//     int cnts = 0;
//     int a[MAXN];
//     while (number != -1) {
//         scanf("%d", &number);
//         a[cnts++] = number;
//     }
//     for (int j=cnts-2; j>=0; j--) {
//         printf("%d ", a[j]);
//     }
//     return 0;
// }