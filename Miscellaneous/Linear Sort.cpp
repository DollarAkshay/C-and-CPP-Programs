#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>

#define MAX 100000001
using namespace std;

int a[MAX],b[MAX];

void linearsort(int n){

	int i,k,l=a[0], h=a[0];
	for (i = 1; i < n; i++){
		l = min(l, a[i]);
		h = max(h, a[i]);
	}

	int* t = (int*) calloc(sizeof(int), h-l+1 );

	for (i = 0; i < n; i++)
		t[a[i] - l]++;
	for (k = 0, i = 0; i <= h - l; i++)
		while (t[i]){
			a[k++] = i + l;
			t[i]--;
		}
}

int split(int L, int R){

	int i = L + 1, j = R, p = b[L], temp;
	while (1){
		while (b[i] <= p && i < R)
			i++;
		while (b[j] >= p && j > L)
			j--;

		if (j > i){
			temp = b[i];
			b[i] = b[j];
			b[j] = temp;
		}
		else{
			temp = b[L];
			b[L] = b[j];
			b[j] = temp;
			return j;
		}
	}

}

void quickSort(int L,int R){

	if (L < R){
		int piv = split(L, R);
		quickSort(L, piv - 1);
		quickSort(piv + 1, R);
	}

}

void checkSorted(int a[],int n){

	int i;
	for (i = 1; i < n; i++){
		if (a[i - 1] > a[i]){
			cout << "Not Sorted. ERROR !!\n";
			break;
		}
	}
	cout << "All sorted.Check Passed\n";

}


int main(){

	srand(time(NULL));

	long long int n,i;

	time_t t;
	for (n = 10000; n < MAX; n *= 10){

		cout << "\nN = "<<n;
		cout << "\n--------------------------------------\n";

		for (i = 0; i < n; i++)
			b[i] = a[i] = rand();

		t = clock();
		linearsort(n);
		t = clock() - t;
		checkSorted(a, n);
		printf("Time Take by Linear Sort : %f \n\n", (float)t / CLOCKS_PER_SEC);

		t = clock();
		quickSort(0, n - 1);
		t = clock() - t;
		checkSorted(b, n);
		printf("Time Take by Quick Sort : %f \n\n\n", (float)t / CLOCKS_PER_SEC);

	}

	_getch();
	return 0;
}