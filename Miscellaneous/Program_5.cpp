#include<stdio.h>
#include<conio.h>

void main(){
	int n,sum=0,i;

	scanf("%d", &n);

	for (i = 1; i <= n; i += 2){
		if (i % 3 == 0 && i % 5 == 0)
			sum += i;
	}

	printf("Sum : %d", d);
	_getch();
}