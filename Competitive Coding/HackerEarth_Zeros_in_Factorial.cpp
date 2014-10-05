
//http://www.hackerearth.com/problem/algorithm/zeros-in-factorial/

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

int z[1000001];
ll int sum[1000001];

void preCompute(){
	int i, j;
	for (i = 1; i <= 1000000; i++){
		for (j = 5; j <= i; j *= 5)
			z[i] += i / j;
		sum[i] = sum[i - 1] + z[i];
	}
}

int main(){

	preCompute();
	int t, a, b;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%d%d", &a, &b);
		printf("%lld\n", sum[b] - sum[a] + z[a]);
	}
}

//Solved