#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

// 因为是每个元素（会有很多个）所以不要定义为指针
typedef struct elem {
    int i; // 行 index
    int j; // 列 index
    int v; // 元素
} Mae;

typedef struct matrix {
    int m; // 行数
    int n; // 列数
    int k; // 非零元素个数
    Mae data[MAX]; // 一维数组；[] 时可以放一个元素
} *Spm;


Spm createArray(int mm, int nn) {
	Spm Arr;
	Arr = (Spm)malloc(sizeof(struct matrix));
	Arr->m = mm;
	Arr->n = nn;
	Arr->k = 0;
	int p = 0;
	char c;
	int ii,jj,v;
	scanf("%d%d%d%c", &ii, &jj, &v, &c);
	while (c!=';') {
		// 如果 MAX 给足了空间，则不需要再给
		// Arr->data[p] = (Mae)malloc(sizeof(struct elem));
		Arr->data[p].i = ii;
		Arr->data[p].j = jj;
		Arr->data[p].v = v;
		p++;
		(Arr->k)++;
		scanf("%d%d%d%c", &ii, &jj, &v, &c);
	}
	return Arr;
}

Spm transArray(Spm Arr) {
	Spm Tarr;
	Tarr = (Spm)malloc(sizeof(struct matrix));
	int p=0;
    int j, k;
    int num[Arr->n];
    int cpo[Arr->n];
	Tarr->m = Arr->n;
	Tarr->n = Arr->m;
	Tarr->k = Arr->k;
	if (Tarr->k > 0) {
        for (p=0; p<Arr->n; p++)
            num[p] = 0;
        // 新矩阵每行的非零数，原矩阵每列的非零数
        for (p=0; p<Arr->k; p++) {
            j = Arr->data[p].j;
            num[j]++;
        }
        // 原矩阵每列第一个非零元素在转置矩阵 data 中的位置
        cpo[0] = 0;
        for (p=1; p<Arr->n; p++)
            cpo[p] = cpo[p-1] + num[p-1];
        
        for (p=0; p<Arr->k; p++) {
        	// 原矩阵非零元素 data 的列 index
            j = Arr->data[p].j;
            // 对应列每一个非零元素在转置矩阵 data 中的位置
            // 列有多个非零元素的，都定位在第一个（所以下面需要 cpo[j]++）
            k = cpo[j];
            Tarr->data[k].i = Arr->data[p].j;
            Tarr->data[k].j = Arr->data[p].i;
            Tarr->data[k].v = Arr->data[p].v;

            // 原矩阵某一列非零数大于一时，index 需要加一
            cpo[j]++;
        }
		//  while (p<Tarr->k) {
		// 	Tarr->data[p].i = Arr->data[p].j;
		// 	Tarr->data[p].j = Arr->data[p].i;
		// 	Tarr->data[p].v = Arr->data[p].v;
		// 	p++;
		// }
	}
	return Tarr;
}


int main() {
	Spm Arr1;
	Arr1 = createArray(2, 3);
	{
		printf("Arr1 %d 行 %d 列，%d 个非零元素。\n", Arr1->m, Arr1->n, Arr1->k);
		for (int p=0; p<Arr1->k; p++) {
			printf("第 %d 行 第 %d 列 是 %d \n", Arr1->data[p].i, Arr1->data[p].j, Arr1->data[p].v);
		}
	}

	Spm Arr2;
	Arr2 = transArray(Arr1);
	{
		printf("Arr2 %d 行 %d 列，%d 个非零元素。\n", Arr2->m, Arr2->n, Arr2->k);
		for (int q=0; q<Arr2->k; q++) {
			printf("第 %d 行 第 %d 列 是 %d \n", Arr2->data[q].i, Arr2->data[q].j, Arr2->data[q].v);
		}
	}

	return 0;
}
