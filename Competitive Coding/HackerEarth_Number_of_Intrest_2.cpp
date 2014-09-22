
//http://www.hackerearth.com/webengage-hiring-challenge-1/algorithm/numbers-of-interest-2-1/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define ll long long
#define MOD 1000000007

int isPrime(int x){
	if (x<2)
		return 0;
	else if (x == 2)
		return 1;
	int lim = sqrt(x);
	FOR(i, 2, lim)
	if (x%i == 0)
		return 0;
	return 1;
}



int main(){

	int t, n;
	ll int sum;
	ll int f = 0, g = 0;
	ll int a[1000000];

	FOR(i, 2, 100000){
		int found = 0;
		int lim = sqrt(i);
		FOR(j, 1, lim){
			if (i%j == 0){
				g += j;
				if (j != 1 && i / j>lim)
					g += i / j;
				if (!found && isPrime(j)){
					f += j;
					found = 1;
				}
			}
		}
		if (!found && isPrime(i))
			f += i;
		a[i] = f + g;
	}

	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		printf("%d\n", a[n] % n);
	}
	return 0;
}

//Solved