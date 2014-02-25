#include<stdio.h>
#include<conio.h>
void main()
{
	int s = 0;
	while (s++<10)
	{
		if (s<4 && s<9)
			continue;
		printf("\n%d\t", s);
	}
	_getch();
}