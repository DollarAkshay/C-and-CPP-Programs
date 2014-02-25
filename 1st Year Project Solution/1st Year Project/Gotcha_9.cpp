#include<conio.h>
#include<stdio.h>

int b[2];
void main()
{
	static int a[2];
	int i;
	for (i = 0; i <= 1; i++)
	{
		printf("%d\t%d", a[i], b[i]);
	}
	_getch();
}