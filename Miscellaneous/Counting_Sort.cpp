#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>

#define MAX 1000000001
using namespace std;

char s[MAX];
int f[256];

void Counting_Sort(int n, char s[]){

	for (int i = 0; i < n; i++)
		f[s[i]]++;

}


int main(){

	srand(time(NULL));

	long long int n, i;

	time_t t;
	for (n = 10000; n < MAX; n *= 10){

		cout << "\nN = "<<n;
		cout << "\n--------------------------------------\n";

		for (i = 0; i < n; i++)
			s[i] = rand()%256;
		

		memset(f, 0, sizeof(f));
		t = clock();
		Counting_Sort(n, s);
		t = clock() - t;
		printf("Time Take by Linear1 Sort : %f \n\n", (float)t / CLOCKS_PER_SEC);

	}

	_getch();
	return 0;
}