#include<stdio.h>
#include<conio.h>

void main(){
	int n, c = 0,i;
	for (i = 1; i <= 10; i++){
		scanf("%d", &n);
		if (n % 5 == 0 && n % 3 == 0)
			c++;
	}
	printf("Numbers divisible by 3 & 5 : %d", c);
	_getch();
}