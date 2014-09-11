#include<stdio.h>
#include<conio.h>

int main(){

	int a[100][100];
	int m, n;
	printf("Enter M x N :");
	scanf("%d%d", &m, &n);
	printf("\nEnter the Matrix elements : ");
	for (int i = 0; i < m*n; i++)
		scanf("%d", &a[i / n][i%n]);
	printf("\nThe Matrix elements are : \n");
	for (int i = 0; i < m*n; i++){
	if (i % n == 0)
		printf("\n");
		printf("%d ", a[i / n][i%n]);

}


	for (int i = 0; i <255;i++)
		printf("\n%d = %c ",i,i);
	_getch();
for (int i = 0; i < m*n; i++)
		printf("%d ", a[i / n][i%n]);

	}





