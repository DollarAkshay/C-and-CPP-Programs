#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>'


int main()
{
	int a[5][5];
	int x = &a[0][0];
	int y = a;
	if (x == y)
		printf("Adresses are the same %d & %d\n",x,y);

	_getch();
}