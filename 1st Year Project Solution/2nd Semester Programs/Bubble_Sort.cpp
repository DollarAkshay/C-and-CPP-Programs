#include<stdio.h>
#include<conio.h>

void main(){

	int a[1000], n, i, j;

	printf("Enter the size of the array : ");
	scanf("%d", &n);
	printf("\nEnter %d elements : ", n);
	for (i = 0; i<n; i++)
		scanf("%d", &a[i]);

	//Bubble Sorting
	for (i = 1; i < n; i++)				//Number of Passes
	for (j = 0; j < n - i; j++)		//Comparison Loop
	if (a[j] > a[j + 1]){
		int temp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = temp;
	}

	printf("\nThe sorted array is : ");
	for (i = 0; i<n; i++)
		printf("%d ", a[i]);

	_getch();
}


