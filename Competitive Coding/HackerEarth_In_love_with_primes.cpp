
//http://www.hackerearth.com/problem/algorithm/in-love-with-primes/

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

	int t, n, d;
	scanf("%d", &t);
	REP(i, t){
		d = 0;
		scanf("%d", &n);
		FOR(j, 2, n / 2){
			if (isPrime(j) && isPrime(n - j)){
				d = 1;
				break;
			}
		}
		puts(d ? "Deepa" : "Arjit");
	}
	return 0;
}

//Solved