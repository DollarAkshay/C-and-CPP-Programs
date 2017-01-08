//http://www.codechef.com/NOV14/problems/FNCS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
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
struct Edge{ int v, w; };

ll int a[100000], sum[100000], f[100000][3], sumf[100000];


void reCalc(int n, int x, int d){

	FOR(i, x, n - 1) sum[i] += d;

	REP(i, n){
		if (f[i][1] >= x)
			f[i][2] = sum[f[i][1]] - sum[f[i][0]] + a[f[i][0]];
		sumf[i] = i ? sumf[i - 1] + f[i][2] : f[i][2];
	}
}


int main(){

	int n, q, t, x, y;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &a[i]);
		sum[i] = i ? sum[i - 1] + a[i] : a[i];
	}
	REP(i, n) {
		scanf("%d%d", &f[i][0], &f[i][1]);
		f[i][0]--;
		f[i][1]--;
		f[i][2] = sum[f[i][1]] - sum[f[i][0]] + a[f[i][0]];
		sumf[i] = i ? sumf[i - 1] + f[i][2] : f[i][2];
	}
	scanf("%d", &q);
	REP(i, q){
		scanf("%d%d%d", &t, &x, &y);
		x--;
		if (t == 2){
			y--;
			printf("%lld\n", sumf[y] - sumf[x] + f[x][2]);
		}
		else{
			int change = y - a[x];
			a[x] = y;
			reCalc(n, x, change);
		}
	}
	return 0;
}

// Partially Solved 10/100 ~ TLE