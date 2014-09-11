//http://www.hackerearth.com/problem/algorithm/day-7-subtraction-game-theory/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

	ll int x, y, t, q, calc = 0;
	int day[1000000];

	day[0] = 1;
	scanf("%d%d%d", &x, &y, &t);
	REP(i, t){
		scanf("%d", &q);
		FOR(j, calc + 1, q){
			day[j] = x*day[j - 1] % MOD - y;
			day[j] %= MOD;
			calc++;
		}
		printf("%d\n", day[q]);
	}
	return 0;
}

//Solved