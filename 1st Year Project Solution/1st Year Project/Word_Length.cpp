#include<stdio.h>
#include<conio.h>

void main(){
	int a=0;
	printf("Word length = %d", ((int)(&a+1)-(int)(&a))*8 );
	_getch();
	


}