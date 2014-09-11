#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>



void main(){

	int i, j, k,n=15;
	for (i = -n ; i <=n; i++){
		for (j = 0; j < abs(i); j++)
			printf("  ");
		if (i != -n && i != n)
		printf("* ");

		for (j = 0; j < n - abs(i) -1; j++)
			printf("  ");
		if (i!=-n && i!=n)
		printf("* ");

		for (j = 0; j <n - abs(i)-1; j++)
			printf("  ");
		printf("*\n");

	}
	_getch();
}