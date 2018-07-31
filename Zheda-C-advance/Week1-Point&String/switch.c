#include<stdio.h>

int main()
{	
	char *ms[12];
	ms[0] = "January";
	ms[1] = "February";
	ms[2] = "March";
	ms[3] = "April";
	ms[4] = "May";
	ms[5] = "June";
	ms[6] = "July";
	ms[7] = "August";
	ms[8] = "September";
	ms[9] = "October";
	ms[10] = "November";
	ms[11] = "December";
	printf("请输入月份： ");
	int month;
	scanf("%d", &month);
	printf("%s\n", ms[month-1]);
    return 0;
}
