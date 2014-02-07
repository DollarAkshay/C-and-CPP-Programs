#include<stdio.h>
#include<conio.h>

void main(){
	int a, b;
	printf("Enter 2 Numbers :");
	scanf("%d %d",&a,&b);
	if (a>b)
		printf("%d is greater than %d",a,b);
	else
		printf("%d is greater than %d",b,a);
	_getch();
}