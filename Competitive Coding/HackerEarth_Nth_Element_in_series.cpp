
//http://www.hackerearth.com/problem/algorithm/nth-element-in-series/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007


int main(){

	register ll int f[10];
	register ll int t, n;
	register int i;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld%lld%lld%lld%lld", &f[0], &f[1], &f[2], &f[3], &f[4], &n);
		if (n<5)
			printf("%lld\n", f[n]);
		else {
			n -= 4;
			i = 4;
			while (i++, n--)
				f[i % 10] = (f[(i - 1) % 10] + f[(i - 2) % 10] + f[(i - 3) % 10] + 2 * f[(i - 4) % 10] + f[(i - 5) % 10]) % MOD;
			printf("%lld\n", f[--i % 10]);
		}
	}
	sp;
	return 0;
}

//Partially Solved 30/100