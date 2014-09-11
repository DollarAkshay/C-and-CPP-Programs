#include<stdio.h>
#include<conio.h>
#include<math.h>

void main(){
	int i, j,k,n=9;



	printf("\n\n\n ~ ~ ~ ~ ~ ~ PATTERN 1 ~ ~ ~ ~ ~ ~ \n");
	for (i = 1; i <= n; i++){
		for ( k = 1; k <= i; k++ ){
			printf("* ");
		}
		for (j = 2*n; j > 2*i; j--){
			printf("  ");
		}
		for (k = 1; k <= i;k++){
			printf("* ");
		}  
		printf("\n");
	}



	printf("\n\n\n ~ ~ ~ ~ ~ ~ PATTERN 2 ~ ~ ~ ~ ~ ~ \n");
	for (i = -n+1; i < n; i++){
		for (j = 0; j < abs(i); j++){
			printf("  ");
		}
		for (k = 0; k < n - abs(i); k++){
			printf("* ");
		}
		printf("\n");
	}



	printf("\n\n\n ~ ~ ~ ~ ~ ~ PATTERN 3 ~ ~ ~ ~ ~ ~ \n");
	for (i = 1; i <= n;i++){
		for (j = n; j>i; j--){
			printf("  ");
		}
		for (k = 1; k <=i; k++){
			printf(" *  ");
		}
		printf("\n");
	}
	for (i = n-1; i>=1; i--){
		for (j = n; j>i; j--){
			printf("  ");
		}
		for (k = 1; k <= i; k++){
			printf(" *  ");
		}
		printf("\n");
	}



	printf("\n\n\n ~ ~ ~ ~ ~ ~ PATTERN 4 ~ ~ ~ ~ ~ ~ \n");
	for (i = -n + 1; i < n; i++){
		for (j = 0; j < abs(i);j++)
			printf("  ");
		for (k = 0; k < 2 * (n - abs(i)) - 1;k++)
			printf("* ");
		printf("\n");
	}



	printf("\n\n\n ~ ~ ~ ~ ~ ~ PATTERN 5 ~ ~ ~ ~ ~ ~ \n");
	for (i = -n; i <= n; i++){
		for (j = 0; j <= abs(i); j++)
			printf("* ");
		for (k = n; k >=j;k--)
			printf("  ");
		for (j = 0; j <= abs(i); j++)
			printf("* ");
		for (k = n; k >= j; k--)
			printf("  ");
		printf("\n");
	}



	printf("\n\n\n ~ ~ ~ ~ ~ ~ PATTERN 6 ~ ~ ~ ~ ~ ~ \n");
	for (i = 1; i <= n;i++){
		for (j = n; j > i; j--)
			printf("   ");
		for (k = -i+1; k < i; k++){
			int x = 2 * i - 1 - abs(k);
			printf("%2d ", x);
		}
		printf("\n");
	}


	_getch();

}