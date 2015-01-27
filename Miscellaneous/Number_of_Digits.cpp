#include<stdio.h>
#include<conio.h>

void main(){
	int n,d=0;
	scanf("%d", &n);
	while (n > 0){
		n /= 10;
		d++;
	}
	printf("No. of Digits : %d", d);
	_getch();
}