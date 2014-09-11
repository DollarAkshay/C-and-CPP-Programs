#include<stdio.h>
#include<conio.h>

int fib(int n){
	if (n <= 2) return 1;
	return fib(n-1) + fib(n-2);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",fib(n));
	_getch();

}