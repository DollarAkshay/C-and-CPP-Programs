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
	ll int f[1001], g[1001];
	f[0] = f[1] = g[0] = g[1] = 0;

	FOR(i, 2, 1000){
		int found = 0;
		sum = 0;
		FOR(j, 2, sqrt(i)){
			if (i%j == 0){
				sum += j;
				if (!found && isPrime(j)){
					f[i] = f[i - 1] + j;
					found = 1;
				}
			}
		}
		if (!found && isPrime(i))
			f[i] = f[i - 1] + i;
		g[i] = g[i - 1] + sum;
	}
	REP(i, 100){
		cout << " " << f[i];
	}
	cout << endl;
	REP(i, 100){
		cout << " " << g[i];
	}
	scanf("%d", &t);
	REP(tc, t){

	}
	return 0;
}