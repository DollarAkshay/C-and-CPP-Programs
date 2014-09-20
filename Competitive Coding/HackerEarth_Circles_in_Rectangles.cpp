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


int main(){

	unsigned ll int t, l, b, d;
	scanf("%llu", &t);
	REP(tc, t){
		scanf("%lld%lld%lld", &l, &b, &d);
		printf("%llu\n", (((l / d) % MOD)*((b / d) % MOD)) % MOD);
	}
	return 0;
}


//Solved
