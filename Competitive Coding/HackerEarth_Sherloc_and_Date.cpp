#include <stdio.h>
#include<string.h>
void main()
{
	char month[100], m;
	int day, year, t, i, j;
	char months[][100] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	scanf("%d", &t);
	for (j = 0; j < t; j++)
	{

		scanf("%d %s %d", &day, &month, &year);
		for (i = 0; i < 12; i++)
		{
			if (strcmp(month, months[i]) == 0)
			{
				m = i;
				i = 12;
			}
		}

		if (day == 1 && m == 0)
		{
			day = 31;
			memset(month, 0, 100);
			m = 11;
			--year;
		}
		else if (day == 1)
		{
			m--;
			day = month_days[m];
			if (m == 1 && (year % 4 == 0 && (year % 100!= 0 || year % 400 == 0)) )
				day++;
		}
		else
		{
			--day;

		}

		printf("%d %s %d\n", day, months[m], year);

	}
}