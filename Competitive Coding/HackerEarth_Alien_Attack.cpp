
//http://www.hackerearth.com/problem/algorithm/alien-attack/

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
#define gc getchar_unlocked

int ans[65000001];

void preCompute(){
	ans[0] = 0;
	ans[1] = 2;
	ans[2] = 7;
	FOR(i, 3, 65000000)
		ans[i] = (ans[i - 1] + (ll int)2 * ans[i - 2]) % MOD;
}


int main(){

	preCompute();

	ll int t, n, a, b, c;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		if (n <= 65000000)
			printf("%d\n", ans[n]);
		else{
			a = ans[65000000 - 1];
			b = ans[65000000];
			FOR(i, 65000001, n){
				c = (2 * a + b) % MOD;
				a = b;
				b = c;
			}
			printf("%lld\n", c);
		}
	}
	return 0;
}

//Partially Solved 70/100