#include <stdio.h>

int main()
{	
	int a, b;
	int cnts = 0;
	int c[100] = {};
	while (cnts != 2)
	{
		scanf("%d %d", &a, &b);
		c[a] += b;
		if (a == 0) {cnts++;}
	}

	int lenc = sizeof(c)/sizeof(c[0]);
	int mixi[400] = {};
	int cntc = 0;
	for (int i = lenc-1; i>=0; i--)
	{
		mixi[cntc] = c[i];
		cntc++;
		mixi[cntc] = i;
		cntc++;
	}

	int cnt0 = 0;	
	int notbegin = 0;
	int lenmixi = sizeof(mixi)/sizeof(mixi[0]);
	for (int i = 0; i < lenmixi; i++)
	{
		// 处理系数
		if (i%2==0 && mixi[i] !=0)
		{
			if (notbegin==0)
			{
				if (mixi[i] == 1 && mixi[i+1] != 0) {printf("");}
				else if (mixi[i] == -1 && mixi[i+1] == 0) {printf("-1");}
				else if (mixi[i] == -1 && mixi[i+1] != 0) {printf("-");}
				else if (mixi[i] >= 1) {printf("%d", mixi[i]);}
				else {printf("%d", mixi[i]);}
				notbegin ++;
			}
			else 
			{
				if (mixi[i] == 1 && mixi[i+1] != 0) {printf("+");}
				else if (mixi[i] == -1) {printf("-");}
				else if (mixi[i] >= 1) {printf("+%d", mixi[i]);}
				else {printf("%d", mixi[i]);}
			}
		}

		// 处理系数全为零的情况
		else if (i%2==0 && mixi[i]==0) {cnt0++;}

		// 处理幂次
		else if (i%2 != 0 && mixi[i-1] != 0)
		{
			if (mixi[i] == 1) {printf("x");}
			else if (mixi[i] == 0) {printf("");}
			else {printf("x%d", mixi[i]);}
		}
	}
	if (cnt0==sizeof(mixi)/sizeof(mixi[0])/2) {printf("%d",0);}
	printf("\n");
	return 0;
}


// #include<stdio.h>
// #include<math.h>
// #define MAX 100
// int main(){
//     int x[MAX] = {0};// 定义 0 
//     int a, b, c=0,n=0, m=0, sum=0;
//     while(c!=2){
//         scanf("%d %d", &a, &b);
//           x[a]+=b;
//         if (a == 0)
//             c++;
//         }
//     for (n = MAX-1; n>= 0; n--){
//         if (x[n] != 0){// 如果某个幂次的系数为 0，就不出现在输入数据中了
//             if (m != 0 && x[n] > 0)// 不是第一个数 如果是正 输出 +
//                 printf("+");
//             if (x[n] < 0)// 如果是负 输出 -
//                 printf("-");
//             if (n != 1) {// 幂不为 1
//                 if (n == 0)// 幂为 0
//                     printf("%d", abs(x[n]));
//                 else if (x[n] == 1 || x[n] == -1)// 系数为 1 或 - 1
//                     printf("x%d", n);
//                 else
//                     printf("%dx%d", abs(x[n]), n);// 幂为其他
//             }else { // 幂为 1 
//                 if(x[n]==1){
//                     printf("x");
//                 }else{
//                     printf("%dx",x[n]);
//                 }
//             }
//             m++; // 第 m 个项输出 
//         }
//         sum += x[n]; // 求多项式的总和 
//     }
//      if (sum == 0)// 总和为 0 
//         printf("0"); 
//     return 0;
// }