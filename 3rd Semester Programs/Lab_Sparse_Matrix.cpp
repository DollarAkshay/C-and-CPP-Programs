#include <stdio.h>
#include <conio.h>

#define MAX 20

typedef struct {
	int row, col, val;
}terms;

terms a[MAX];

void search(int key, int c);

void main(){
	int i, j, count = 0, key, m, n, index=1;
	int SM[MAX][MAX];

	//Reading the Dimensions
	printf("Enter the rows and columns : ");
	scanf("%d%d", &n, &m);

	//Reading Sparse Matrix
	printf("\nEnter the elements :\n");
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			scanf("%d",&SM[i][j]);

	//Seperating out non-zero terms

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			int temp = SM[i][j];
			if (temp){
				count++;
				a[index].col = j;
				a[index].row = i;
				a[index++].val = temp;
			}
		}
	}
	
	//Zeroth row contains general info
	a[0].col = m;
	a[0].row = n;
	a[0].val = count;

	//Display Sparse Matrix
	printf("\n ROWS  COLUMNS  VALUE");
	for (i = 0; i < count; i++)
		printf("\n   %d \t  %d \t  %d", a[i].row, a[i].col, a[i].val);

	//Search for Key
	printf("\n\nEnter the key to be searched : ");
	scanf("%d", &key);
	search(key, count);
	_getch();

}

void search(int key, int n){

	int i, found = 0;
	for (i = 1; i < n; ++i){
		if (a[i].val == key){
			found = 1;
			break;
		}
	}
	if (found)
		printf("\nKey %d was found at row %d and column %d", key, a[i].row, a[i].col);
	else
		printf("\nKey not found");

}


/*

Output :
--------------------------------
Enter the rows and columns : 4 5

Enter the elements :
1 0 0 0 8
0 0 0 5 0
7 0 0 2 0
0 0 0 0 3

ROWS  COLUMNS  VALUE
4      5       6
0      0       1
0      4       8
1      3       5
2      0       7
2      3       2

Enter the key to be searched : 7

Key 7 was found at row 2 and column 0

*/