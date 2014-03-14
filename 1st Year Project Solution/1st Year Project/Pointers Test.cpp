#include<stdio.h>
#include<conio.h>

void main(){
	int a = 10, b = 5;
	int *i, *j;
	j = &a;
	printf("\nJ = %p pointer", j);
	printf("\nJ = %d integer", j);
	printf("\nValue at j = %d\n", *j);
	j++;
	printf("\nJ = %p pointer", j);
	printf("\nJ = %d integer", j);
	printf("\nValue at j = %d", *j);
	_getch();


}

