/*This is a program to understand flags in C*/

#include<stdio.h>
#include<conio.h>


void main(){
	
	int a[3][3] = { -1, 7, 13, -16, 8, 100, 5, -6, 0 };


	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)


			printf(" %d ", a[i][j]);

		printf("\n");
	}

	_getch();


}