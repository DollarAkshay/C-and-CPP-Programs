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
#define ll _int64
#define MOD 1000000007

int gcd(int a, int b){
	int c;
	while (a != 0){
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

int gcdr(int a, int b){
	if (a == 0) return b;
	return gcdr(b%a, a);
}


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

	int t, n, a[10001];
	a[1] = 0;
	FOR(i, 2, 100){
		if (isPrime(i)){
			a[i] = a[i - 1] + i - 1;
			continue;
		}
		int c = 0;
		FOR(j, 1, i - 1){
			if (gcd(j, i) == 1)
				c++;
		}
		a[i] = a[i - 1] + c;
	}
	REP(i, 100){
		printf("%d, ", a[i]);
	}
	
	return 0;
}