#include<stdio.h>
#include<conio.h>

void main(){
	int a[100], n;
	int i, j;

	printf("Enter the size of the array : ");
	scanf("%d", &n);
	printf("\nEnter %d elements : ", n);
	for (i = 0; i<n; i++)
		scanf("%d", &a[i]);

	//Insertion Sorting
	for (i = 1; i < n; i++){
		for (j = i; j; j--){
			if (a[j] < a[j - 1]){
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}

	printf("\nThe sorted array is : ");
	for (i = 0; i<n; i++)
		printf("%d ", a[i]);
	_getch();
		


}