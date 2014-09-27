
//http://www.hackerearth.com/problem/approximate/fun-with-sequences/

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

char f[5000001];

int main(){

	ll int t, n, rep, i;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		if (f[n]){
			rep = n;
			break;
		}
		else
			f[n]++;
	}
	printf("%lld ", rep);
	for (i = 1; i<t; i++){
		printf("%lld ", i);
	}
	return 0;
}

//Solved