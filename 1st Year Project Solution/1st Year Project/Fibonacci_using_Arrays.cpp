#include<stdio.h>
#include<conio.h>

int main(){
	int a[99],i,n;
	a[0] = 0;
	i = a[1] = 1;
	scanf("%d", &n);
	while (++i < n)
		a[i] = a[i - 1] + a[i - 2];
	for (i = 0; i<n; printf("%d,", a[i++]));
	_getch();
}
