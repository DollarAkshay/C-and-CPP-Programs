/*This is a program to understand flags in C*/

#include<stdio.h>
#include<conio.h>


void main(){
	int a = 123456, b = 10;
	float pi = 3.1415,micro = 0.00123,z=0.1;
	printf("%4d\n", a);
	printf("%8.4d\n", a);
	printf("%5.4d\n", b);
	printf("%.4d\n", b);
	printf("%.7f\n", pi);
	printf("%2.2f\n", pi);
	printf("%5.2f\n", pi);
	_getch();


}