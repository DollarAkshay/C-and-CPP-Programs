
//http://www.hackerearth.com/problem/algorithm/iit-delhi-and-arjit-singh/

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
struct Edge{ int v, w; };

int gcd(int a, int b){
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}


int main(){

	int t, n, p, i, j;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &p);
		int ans = n / p;
		for (i = 2 * p; i <= n; i += p){
			for (j = i + p; j <= n; j += p){
				if (gcd(i, j) == p)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	sp;
	return 0;
}

//Not Solved ~ TLE