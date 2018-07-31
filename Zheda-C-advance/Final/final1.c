#include <stdio.h>

int max(int a[], int len)
{
    int maxid = 0;
    for ( int i=1; i<len; i++)
    {
        if ( a[i] > a[maxid] )
        {
            maxid = i;
        }
    }
    return a[maxid];
}

int min(int a[], int len)
{
    int minid = 0;
    for ( int i=1; i<len; i++)
    {
        if ( a[i] < a[minid] )
        {
            minid = i;
        }
    }
    return a[minid];
}

int main()
{
    int n, m;
    scanf("%d", &n);
    int i = 0, j = 0, cnt = 0;
    int x[n];
    int y[n];
    
    while (cnt < n*2) {
    	scanf("%d", &m);
    	if (cnt % 2 == 0) { x[i++] = m; }
    	else { y[j++] = m; }
    	cnt ++;
    }

    printf("%d %d %d %d\n", min(x, n), min(y, n), max(x, n), max(y, n));

    return 0;

}