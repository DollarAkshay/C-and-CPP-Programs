#include<stdio.h>
#include<math.h>
void solve(unsigned long long, unsigned long long, unsigned long long);
int main()
{
	unsigned long long  N, M, Z;
	int test_case;
	scanf("%d", &test_case);
	while (test_case--)
	{
		scanf("%llu", &Z);
		scanf("%llu", &N);
		scanf("%llu", &M);
		solve(N, M, Z);
	}
	return 0;
}
void solve(unsigned long long N, unsigned long long M, unsigned long long Z)
{
	unsigned long long number2, no_of_ways = 0;
	int sqrt_val = 0, number1;
	sqrt_val = sqrt((double)Z);
	for (number1 = 1; number1<=sqrt_val; number1++)
	{
		number2 = Z/number1;
		if ((number2*number1)==Z)
		{
			if (number2<=M)
			{
				no_of_ways++;
			}
			if (number2<=N && number1!=number2)
			{
				no_of_ways++;
			}
		}
	}
	printf("%llu\n", no_of_ways);
}