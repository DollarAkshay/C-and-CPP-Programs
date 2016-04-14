
// Aishwarya

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>

int mat[100][100];
int i, j, row, col;
int maxint(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

int findMax(int i, int j)
{
	int pebbles;
	if (i>row-1 || j>col-1)    
	{
		return 0;
	}
	else if (i==row-1 && j==col-1)
	{
		return mat[i][j];
	}
	else
	{
		pebbles = mat[i][j]+ maxint(findMax(i, j+1), findMax(i+1, j));	

		return pebbles;
	}
}

int main()
{
	int result;
	printf("Enter the number of columns\n");
	scanf("%d", &col);
	printf("Enter the number of rows\n");
	scanf("%d", &row);
	printf("Enter the matrix\n");
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	result = findMax(0, 0);      
	printf("max pebbles are %d\n", result);
	system("pause");
	return 0;
}