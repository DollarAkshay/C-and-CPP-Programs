#include<stdio.h>
#include<conio.h>

void main(){

	int a[100],i,n;
	for (i = scanf("%d",&n)-1;i < n;scanf("%d", &a[i++]));
	for (i = 0; i < n; printf("%d ", a[i++]));

	_getch();
}