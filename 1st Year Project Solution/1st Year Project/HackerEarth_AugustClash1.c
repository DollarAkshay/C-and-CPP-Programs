
#include <stdio.h>
#include <stdlib.h>

long long int count[4];
long long int a[200000];

long long int compare(const void * a, const void * b)
{
	return (*(long long int*)a - *(long long int*)b);
}

void checkPrimes(int n){
	int d2 = 0, d3 = 0, d5 = 0, d7 = 0;
	while (n && (!d2 || !d3 || !d5 || !d7)){
		switch (n % 10){
		case 2: if (!d2){ count[0]++; d2 = 1; } break;
		case 3: if (!d3){ count[1]++; d3 = 1; } break;
		case 5: if (!d5){ count[2]++; d5 = 1; } break;
		case 7: if (!d7){ count[3]++; d7 = 1; } break;
		}
		n /= 10;
	}
}

long int ncr(long long int n, long long int r){
	if (n == r)
		return 1;
	long long int x = 1, i = 1;
	r = n - r>r ? n - r : r;
	while (n - r)x = x*n-- / i++;
	return x;
}

void removeDuplicates(int n){
	for (int i = 0; i<n; i++){
		if (a[i] == a[i + 1]){
			for (int j = i + 1; a[j] == a[i]; j++)
				a[j] = 0;
		}
	}
}


int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(long long int), compare);
	removeDuplicates(n);
	for (i = 0; i<n; i++){
		checkPrimes(a[i]);
	}
	long long int trip = 0;
	if (count[0] >= 3)
		trip += ncr(count[0], 3);
	if (count[1] >= 3)
		trip += ncr(count[1], 3);
	if (count[2] >= 3)
		trip += ncr(count[2], 3);
	if (count[3] >= 3)
		trip += ncr(count[3], 3);
	printf("%ld\n", trip);
}