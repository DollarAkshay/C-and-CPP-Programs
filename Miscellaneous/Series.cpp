#include<stdio.h>
#include<conio.h>

void main(){
	int n,i;

	//Input n
	scanf("%d", &n);

	for (i = 1; i <= n; i=i*10+1){
		printf("%d ", i);
	}
	_getch();
}