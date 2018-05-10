#include <stdio.h>
#include <algorithm>
#include <list>

void bubblesort(int A[], int n) {

    for ( bool sorted = false; sorted = !sorted; n-- )
        for (int i = 1; i < n; i++) // 从左到右逐对检查 A[0,n) 内各相邻元素
            if (A[i-1] > A[i]) {
                std::swap(A[i-1], A[i]);
                sorted = false; // 清楚（全局）有序标志
            }
}
void printArray(int arr[], int size) {
    int i;
    for (i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {

    int arr[] = {2, 5, 6, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr, n);
    printArray(arr, n);
    return 0;
}
