#include<stdio.h>
#include<conio.h>

void main(){
	int i, j,k,n=20;


	for (i = 1; i <= n; i++){
		for (j = n; j > i; j--)
			printf(" ");
		for (k = 1; k <= i; k++){
			if (k % 2 == 1 && i % 2 == 1)
				printf("- ");
			else
 				printf("+ ");
	}
		printf("\n");
	}
	_getch();

}