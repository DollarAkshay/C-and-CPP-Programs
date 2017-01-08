
//https://www.hackerrank.com/contests/w11/challenges/sherlock-and-square

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

	int t, n;
	ll int pow;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		pow = 1;
		while (n--)
			pow = (pow * 2) % MOD;
		pow--;
		pow = (pow * 2) % MOD;
		printf("%d\n", (4 + pow) % MOD);
	}
	return 0;
}

//Solved