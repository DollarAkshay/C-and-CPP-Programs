#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int fact[100000], len = 0;

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int t, n, i;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		if (n == 1){
			cout << "1" << endl;
			continue;
		}
		int count = 2;
		int limit = sqrt(n);
		for (i = 2; i <= limit; i++){
			if (n%i == 0){
				count++;
				fact[len++] = i;
				if (n / i > limit){
					count++;
					fact[len++] = n/i;
				}
			}
		}
		qsort(fact, len, sizeof(int), compare);
		for (i = 0; i < len; i++){
			printf("%d\n",fact[i]);
		}
		printf("Count = %d\n", count);
	}
}
