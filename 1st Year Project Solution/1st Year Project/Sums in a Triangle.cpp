//http://www.codechef.com/problems/SUMTRIAN
/*Let's consider a triangle of numbers in which a number appears in the first line, two numbers appear in the second line, three in the third line, etc. Develop a program which will compute the largest of the sums of numbers that appear on the paths starting from the top towards the base, so that:
on each path the next number is located on the row below, more precisely either directly below or below and one place to the right;
the number of rows is strictly positive, but less than 100
all numbers are positive integers between O and 99.
Input

In the first line integer n - the number of test cases (equal to about 1000).
Then n test cases follow. Each test case starts with the number of lines which is followed by their content.
Output

For each test case write the determined value in a separate line.
Example

Input:
2
3
1
2 1
1 2 3
4 
1 
1 2 
4 1 2
2 3 1 1 

Output:
5
9
*/

#include<conio.h>
#include<stdio.h>

#include <stdio.h>
#include <stdlib.h>
int s[100][100];
int max(int x, int y)
{
	if (x>y)
		return x;
	else
		return y;
}

void printTriangle(int x){
	printf("\nTriangle:\n");
	for (int i = 0; i < x; i++){
		for (int j = 0; j <= i; j++)
			printf("%3d ", s[i][j]);
		printf("\n");
	}
	printf("~~~~~~~~~~~~~\n");


}
int solve(int x)
{
	int i, j;
	if (x == 1)
		return s[0][0];
	else
	{
		for (i = x - 2; i >= 0; i--)
		{
			for (j = 0; j <= i; j++)
			{
				s[i][j] += max(s[i + 1][j], s[i + 1][j + 1]);
				
			}
			printTriangle(x);
		}
	}
	return s[0][0];
}
int main()
{
	int tc, row, i, j;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &row);
		for (i = 0; i<row; i++)
		{
			for (j = 0; j <= i; j++)
			{
				scanf("%d", &s[i][j]);
			}
		}
		printf("%d\n", solve(row));
	}
	_getch();
}