
//https://www.hackerrank.com/contests/codathon/challenges/nishu-the-student-and-prabhu-the-mathematician

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
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

int sum[10000000];

void preCompute(){

	int a = 0, b = 1;
	REP(i, 10000000){
		sum[i + 1] = sum[i] + b;
		sum[i + 1] %= MOD;
		b = b + a;
		b %= MOD;
		a = b - a;
		a %= MOD;
		if (a<0)
			a += MOD;
	}
}

int main(){

	sum[0] = 0;
	preCompute();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		printf("%d\n", sum[n - 1]);
	}
	return 0;
}

//Paritally Solved 40/80
