#include<stdio.h>
#include<conio.h>

void main(){
	int a[10][10], b[10][10], c[10][10]; 
	int m, n, p, q, i, j, k;

	printf("Enter the size of A : ");
	scanf("%d%d",&m,&n);
	printf("Enter the size of B : ");
	scanf("%d%d", &p, &q);
	if (p == n){
		printf("Enter the Matrix  A : ");
		for (i = 0; i < m*n; i++)
			scanf("%d", &a[i/n][i%n]);
		printf("Enter the Matrix  B : ");
		for (i = 0; i < p*q; i++)
			scanf("%d", &b[i/q][i%q]);


		// Multiplication
		for (i = 0; i < m; i++){	
			for (j = 0; j < q; j++){	
				c[i][j] = k = 0;
				while (k < n){
					c[i][j] += a[i][k] * b[k][j];
					printf("\n%d %d %d %d", c[i][j],a[i][k],b[k][j],k);
					k++;
				}
			}
		}


		//Printing A,B & C
		printf("\nMatrix  A : ");
		for (i = 0; i < m*n; i++){
			if (i%n == 0)
				printf("\n");
			printf("%6d", a[i/n][i%n]);
		}	
		printf("\nMatrix  B : ");
		for (i = 0; i < p*q; i++){
			if (i%q == 0)
				printf("\n");
			printf("%6d",b[i/q][i%q]);
		}
		printf("\nMatrix  C : ");
		for (i = 0; i < m*q; i++){
			if (i%q == 0)
				printf("\n");
			printf("%6d", c[i/q][i%q]);
		}
	}
	_getch();
}

