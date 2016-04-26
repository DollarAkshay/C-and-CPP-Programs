
//https://www.hackerrank.com/challenges/sansa-and-xor

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

ll int a[100000];

int main(){
	ll int t, n, ans = 0;
	scanf("%lld", &t);
	REP(tc, t){
		ans = 0;
		scanf("%lld", &n);
		REP(i, n){
			scanf("%lld", &a[i]);
			ans ^= i % 2 ? 0 : a[i];
		}
		printf("%lld\n", n % 2 ? ans : 0);
	}
	return 0;
}

//Solved