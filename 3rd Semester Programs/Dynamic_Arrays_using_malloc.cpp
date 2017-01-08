#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main(){

	int n, i, *A;

	printf("Enter the array size : ");
	scanf("%d", &n);

	A = (int*) malloc(n*sizeof(int)); //Dynamic Array.Size allocated at runtime

	//Reading array 'A'
	printf("\nEnter the elements : ");
	for (i = 0; i < n; i++)
		scanf("%d", A + i);

	//Printing Array 'A'
	printf("\nArray A : ");
	for (i = 0; i < n; i++)
		printf("%d ", *(A + i));
	
	_getch();
}

/*
Output :
---------------------
Enter the array size : 5

Enter the elements : 1 3 5 2 4

Array A : 1 3 5 2 4

*/