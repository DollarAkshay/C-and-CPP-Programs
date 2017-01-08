
//http://www.hackerearth.com/november-clash/algorithm/broken-amit/

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

struct girl{
	int l, d, t;
};

struct girl g[17];

bool compare(girl lhs, girl rhs){
	return lhs.t > rhs.t;
}

ll int lovesum(int n){
	ll int sum = 0;
	REP(i, n) sum += g[i].l;
	return sum;

}


ll int kiss(int n){

	ll int gross = 0;
	REP(i, n){
		gross += lovesum(n);
		FOR(j, i + 1, n - 1)
			g[j].l -= g[j].t;
	}
	return gross;
}

int main(){

	int n;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", &g[i].l);
	REP(i, n){
		scanf("%d", &g[i].d);
		g[i].t = g[i].d*i;
	}
	sort(g, g + n, compare);
	ll int ans = kiss(n);
	printf("%lld", ans);
	return 0;
}

// Solved