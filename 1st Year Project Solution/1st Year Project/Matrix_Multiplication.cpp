#include<stdio.h>
#include<conio.h>

void main(){
	int i, j, k, l;
	int m = 2, n = 3, p = 4;
	int a[2][3] = { { 4, 5, 6 }, { 7, 8, 9 } };
	int	b[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	int c[2][4];
	
	for (i = 0; i < m; i++){			//Speciies Row
		for (j = 0; j < p; j++){		//Speciies Column
			c[i][j] = l = 0;
			while (l < n){
				c[i][j] = c[i][j] + a[i][l] * b[l][j];
				l++;
			}
		}
	}

	for (i = 0; i <m; i++){				//Speciies Row
		for (j = 0; j < p; j++){		//Speciies Column
			printf("%3d ",c[i][j]);
		}
		printf("\n");
	}

	_getch();
}