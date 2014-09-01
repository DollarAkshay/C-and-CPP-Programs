//http://www.hackerearth.com/problem/algorithm/karan-and-prime-numbers/

#include <stdio.h>
#include <math.h>

int isPrime(int n){
	if (n<2)
		return 0;
	if (n == 2)
		return 1;
	int limit = sqrt((float)n), i;
	for (i = 2; i <= limit; i++)
	if (n%i == 0)
		return 0;
	return 1;
}



int main()
{
	int t, l, r, i;
	long long int sum;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &l, &r);
		for (i = l; i <= r; i++)
		if (isPrime(i))
			sum += i;
		printf("%lld\n", sum);
		sum = 0;
	}


}
