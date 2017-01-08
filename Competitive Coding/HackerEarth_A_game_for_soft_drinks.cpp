
//http://www.hackerearth.com/problem/algorithm/a-game-for-soft-drinks/

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

	int t, a, b, c;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d%d", &a, &b, &c);
		if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
			puts("Aishwarya");
		else
			puts("Ashima");

	}
	return 0;
}

//Solved 100/100