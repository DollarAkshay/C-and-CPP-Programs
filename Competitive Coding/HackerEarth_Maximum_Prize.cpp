
//http://www.hackerearth.com/problem/algorithm/maximum-prize/

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

	unsigned long long int ans = 0;
	int t, n, k;
	int a[1000000];
	scanf("%d", &t);
	REP(tc, t){
		ans = 0;
		scanf("%d%d", &n, &k);
		REP(i, n){
			scanf("%d", &a[i]);
		}
		SORT(a, n);
		for (int i = 1; i <= k && i <= n; i++){
			ans += a[n - i];
		}
		printf("%llu\n", ans);
	}
	return 0;
}

//Solved 100/100