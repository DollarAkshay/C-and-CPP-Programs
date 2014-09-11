#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int a[1000000];

void swap(int *a, int *b){
	int *t = a;
	*a = *b;
	*b = *t;
}

void printArray(int n){
	int i = 0;
	while (i < n)
		printf("%d ", a[i++]);
	printf("\n");

}


void main(){
	srand(time(NULL));

	int x, read = 1;
	int key = 1;
	const int n = 100000;
	clock_t t;
	FILE *fp;
	fp = fopen("Array.txt", "r+");
	for (int i = 0; i < n; i++){
		fscanf(fp, "%d", &a[i]);
	}


	t = clock();
	//Insertion Sort
	for (int i = 1; i < n; i++){
		int t = a[i];
		for (int j = i; j; j--){
			if (t<a[j - 1]){
				a[j] = a[j - 1];
				if (j - 1 == 0)
					a[j - 1] = t;
			}
			else{
				a[j] = t;
				break;
			}
		}
	}

	t = clock() - t;
	printf("\nIt took %f sec to sort %d num bers by Insertion sort\n", (float)t/CLOCKS_PER_SEC, n);
	_getch();
}


// Normal Swaping  took 8.91 seconds on average.
// Linear Shifting took 6.19 seconds on average.