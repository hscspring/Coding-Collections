#include<stdio.h>


struct date
{
	int month;
	int day;
	int year;
};

int main(int argc, char const *argv[])
{
	// struct date today = {07, 31, 2014};
	struct date today;
	today = (struct date){07, 31, 2014};
	struct date thismonth = {.month=7, .year=2015};
	struct date day;
	day = today;
	day.year = 2015;

	struct date *pDate = &today;
	// today.month = 07;
	// today.day = 31;
	// today.year = 2014;
	printf("Today's date is %i-%i-%i.\n", today.year, today.month, today.day);
	printf("This month is %i-%i-%i.\n", thismonth.year, thismonth.month, thismonth.day);
	printf("The day is %i-%i-%i.\n", day.year, day.month, day.day);

	printf("address of today is %p\n", pDate);
	return 0;
}