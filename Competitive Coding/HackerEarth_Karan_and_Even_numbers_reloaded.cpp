//http://www.hackerearth.com/problem/algorithm/karan-and-even-numbers-reloaded/

#include <stdio.h>

int main()
{
	long long int i;
	while (scanf("%lld", &i), i + 1){
		i % 2 ? 0 : printf("%lld\n", i);
	}
}

//Solved - Jujubie

