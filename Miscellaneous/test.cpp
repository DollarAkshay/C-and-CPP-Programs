//Debugging Akshay Pai's Code

#include<stdio.h> 
#include<conio.h>
#include <string>
#include <iostream>

using namespace std;

int compare(const void * a, const void * b)
{
	return (*(int*)b - *(int*)a);
}

int main()
{
	long long n;

	cin >> n;
	long long *a = new long long[n];
	long long *b = new long long[n];
	for (long long i = 0; i<n; i++)
		cin >> a[i];
	for (long long i = 0; i<n; i++)
		cin >> b[i];

	qsort(a, n, sizeof(long long int), compare);
	qsort(b, n, sizeof(long long int), compare);

	long long sum = 0;
	for (long long i = 0; i<n; i++)
		sum = sum + (a[i] * b[i]);
	cout << sum << endl;
	return 0;
}