
//https://www.hackerrank.com/contests/infinitum8/challenges/pairwise-sum-and-divide

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
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

int main(){

	ll int t, n, one, two;
	ll int a[200000];
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		one = 0;
		two = 0;
		REP(i, n){
			scanf("%lld", &a[i]);
			if (a[i] == 1)
				one++;
			else if (a[i] == 2)
				two++;
		}
		ll int sum = 0;
		if (one){
			sum += (one)*(n - one);
			sum += one*(one - 1);
		}
		if (two)
			sum += two*(two - 1) / 2;
		printf("%lld\n", sum);
	}
	return 0;
}
// Solved

