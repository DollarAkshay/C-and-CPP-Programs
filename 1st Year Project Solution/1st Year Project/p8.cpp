#include<stdio.h>
#include<conio.h>

void main(){
	int i, j, k, n = 5,c=1;

	for (i = 1; i<=n; i++){
		for (k =1; k <= n-i; k++){
			printf("      ");
		}
		for (j = 1; j <= 2 * i - 1;j++){
			printf("%-6d", c*c++);
		}
		printf("\n");
	}

	_getch();
}
