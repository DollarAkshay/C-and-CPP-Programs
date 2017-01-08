
//http://www.hackerearth.com/webengage-hiring-challenge-1/algorithm/amazing-test/

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

int compare(const void* a, const void *b){
	return *(ll int*)b - *(ll int*)a;
}
int main(){

	int t, n, x, r1 = 0, r2 = 0;

	scanf("%d", &t);
	REP(tc, t){
		int a[100];
		scanf("%d%d", &n, &x);
		REP(i, n)
			scanf("%d", &a[i]);

		qsort(a, n, sizeof(int), compare);

		REP(i, n){
			if (r1<r2)
				r1 += a[i];
			else
				r2 += a[i];
		}

		puts(r1>x || r2>x ? "NO" : "YES");
		r1 = r2 = 0;
	}

	return 0;
}

//Partially Solved 40/100