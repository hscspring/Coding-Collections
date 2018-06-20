#include <stdio.h>

int max(int a[], int len)
{
    int maxid = 0;
    for (int i=1; i<len; i++)
    {
        if ( a[i] > a[maxid])
        {
            maxid = i;
        }
    }
    return maxid;
}

int min(int a[], int len)
{
    int minid = 0;
    for (int i=1; i<len; i++)
    {
        if ( a[i] < a[minid])
        {
            minid = i;
        }
    }
    return minid;
}


int main()
{
    int n;
    scanf("%d", &n);
    int i,j;
    // int **a;
    // int *locx;
    // int *locy;
    int a[n][n];
    int locx[n*2];
    int locy[n*2];
    // locx = (int *) malloc(sizeof(int *) *n);
    // locy = (int *) malloc(sizeof(int *) *n);
    // a = (int **) malloc(sizeof(int *) *n);
    // for (i = 0; i < n; i++) 
    //     { a[i] = (int *) malloc(sizeof(int) * n); }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }

    for (i = 0; i < n*2; i+=2)
    {
        int x[n];
        int y[n];
        for (j = 0; j < n; j++)
        {
            x[j] = a[i/2][j];
            y[j] = a[j][i/2];
        }
        locx[i] = i/2;
        locx[i+1] = max(x, n);;
        locy[i] = min(y, n);
        locy[i+1] = i/2;
    }

    int count = 0;
    for (i = 0; i < n*2; i+=2)
    {
        for (j = 0; j < n*2; j+=2)
        {
            if (locx[i] == locy[j] && locx[i+1] == locy[j+1])
            {
                printf("%d %d\n", locx[i], locx[i+1]);
                count ++;
            }
        }
    }
    if (count == 0) { printf("NO"); }
    return 0;
}