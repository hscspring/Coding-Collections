#include <stdio.h>
#include <stdlib.h>


/* 

转置操作必然报错，创建无错。

*/



// 因为是每个元素（会有很多个）所以不要定义为指针
typedef struct elem {
    int i; // 行 index
    int j; // 列 index
    int v; // 元素
} *Mae;

typedef struct matrix {
    int m; // 行数
    int n; // 列数
    int k; // 非零元素个数
    Mae *data;
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
		// 为每个结构体赋空间，因为每个结构体都是一个指针
		Arr->data[p] = malloc(sizeof(struct elem));
		Arr->data[p]->i = ii;
		Arr->data[p]->j = jj;
		Arr->data[p]->v = v;
		p++;
		(Arr->k)++;
		scanf("%d%d%d%c", &ii, &jj, &v, &c);
	}
	return Arr;
}

Spm transArray(Spm Arr) {
	Spm Tarr;
	Tarr = (Spm)malloc(sizeof(struct matrix));
	Tarr->m = Arr->n;
	Tarr->n = Arr->m;
	Tarr->k = Arr->k;
	int p=0;
	if (Tarr->k > 0) {
		while (p<Tarr->k) {
			Tarr->data[p] = malloc(sizeof(struct elem));
			Tarr->data[p]->i = Arr->data[p]->j;
			Tarr->data[p]->j = Arr->data[p]->i;
			Tarr->data[p]->v = Arr->data[p]->v;
			p++;
		}
	}
	return Tarr;
}


int main() {
	Spm Arr1;
	Arr1 = createArray(6, 6);
	{
		printf("Arr1 %d 行 %d 列，%d 个非零元素。\n", Arr1->m, Arr1->n, Arr1->k);
		for (int p=0; p<Arr1->k; p++) {
			printf("第 %d 行 第 %d 列 是 %d \n", Arr1->data[p]->i, Arr1->data[p]->j, Arr1->data[p]->v);
		}
	}

	Spm Arr2;
	Arr2 = transArray(Arr1);
	{
		printf("Arr2 %d 行 %d 列，%d 个非零元素。\n", Arr2->m, Arr2->n, Arr2->k);
		for (int q=0; q<Arr2->k; q++) {
			printf("第 %d 行 第 %d 列 是 %d \n", Arr2->data[q]->i, Arr2->data[q]->j, Arr2->data[q]->v);
		}
	}

	return 0;
}