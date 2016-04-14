// Anagha


#include<stdio.h>
#include<conio.h>
void main()
{

	int row, col;
	int a[100][100];
	int i = 0, j = 0;

	printf(" Enter the limit row \n");
	scanf("%d", &row);
	printf(" Enter the coloum col \n");
	scanf("%d", &col);
	printf(" Enter the matrix \n");
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	getch();
}