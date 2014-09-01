//http://www.hackerearth.com/problem/algorithm/candy-distribution-2/

#include <stdio.h>

int main()
{
	int t, n, a;
	long long int sum = 0;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		int temp = n;
		while (n--){
			scanf("%d", &a);
			sum += a;
		}
		printf("%lld\n", sum - temp + 1);
		sum = 0;
	}
}

//Solved