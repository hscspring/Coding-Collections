#include <stdio.h>


double rate(int a, int b)
{
    return a*1.0/b;
}

int main()
{
    int a,b,c,d;
    scanf("%d/%d %d/%d", &a, &b, &c, &d);

    double r1 = rate(a, b);
    double r2 = rate(c, d);

    if (r1 > r2) { printf("%d/%d > %d/%d\n", a, b, c, d); }
    else if ( r1 < r2 ) { printf("%d/%d < %d/%d\n", a, b, c, d); }
    else  { printf("%d/%d = %d/%d\n", a, b, c, d); }

    return 0;

}

// int main()
// {
//     int a,b,c,d;
//     scanf("%d/%d %d/%d", &a, &b, &c, &d);
    
//     if (a*c < b*d) { printf("%d/%d < %d/%d\n", a, b, c, d); }
//     else if (a*c > b*d) { printf("%d/%d > %d/%d\n", a, b, c, d); }
//     else { printf("%d/%d = %d/%d\n", a, b, c, d); }

//     return 0;
// }