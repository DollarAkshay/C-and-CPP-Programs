#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define FOR(i,a,b) for(ll int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))

#define MAX 30000000

char *primes;

long long int reverse(long long int n){
	long long int ans = 0, temp = n;
	while (n){
		ans = ans * 10 + n % 10;
		n /= 10;
	}
	if (ans == temp)
		return 0;
	return ans;
}

int main(){

	long long int i, k, lim = sqrt(MAX), r;

	primes = (char*)calloc(MAX + 2, sizeof(char));
	*(primes) = *(primes + 1) = 1;
	for (i = 2; i <= lim; i++)
	if (!*(primes + i))
	for (k = i << 1; k <= MAX; k += i)
		*(primes + k) = 1;

	for (i = 13; i <= MAX - 1; i++){
		if (!*(primes + i)){
			r = reverse(i);
			if (!*(primes + r)){
				printf("%lld\n", i);
				*(primes + r) = 1;
			}
		}
	}
	return 0;
}