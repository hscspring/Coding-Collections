/*
逆序输出（10 分）
题目内容：

你的程序会读入一系列的正整数，预先不知道正整数的数量，一旦读到 - 1，就表示输入结束。然后，按照和输入相反的顺序输出所读到的数字，不包括最后标识结束的 - 1。



输入格式:

一系列正整数，输入 - 1 表示结束，-1 不是输入的数据的一部分。



输出格式：

按照与输入相反的顺序输出所有的整数，每个整数后面跟一个空格以与后面的整数区分，最后的整数后面也有空格。



输入样例：

1 2 3 4 -1



输出样例：

4 3 2 1 

时间限制：500ms 内存限制：32000kb
*/

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