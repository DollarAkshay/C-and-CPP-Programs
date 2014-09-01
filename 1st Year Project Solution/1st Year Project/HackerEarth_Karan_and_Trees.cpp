//http://www.hackerearth.com/HackTheSlack/algorithm/karan-and-trees/

#include <stdio.h>

int main()
{
	int t;
	long long int a, b;
	scanf("%d", &t);
	while (t--){
		scanf("%lld%lld", &a, &b);
		while (a != b)
		if (a>b) a /= 2;
		else b /= 2;
		printf("%lld\n", a);
	}
}

//Solved