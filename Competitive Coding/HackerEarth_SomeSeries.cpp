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

#define MAX 10000000

int seg[MAX], pow_max;

void preCalc(){

	seg[0] = -1; seg[1] = 1;
	ll int pow = 3;
	for (ll int i = 2; i<MAX; i++){
		pow = (3 * pow) % MOD;
		seg[i] = (((ll int)2 * seg[i - 1]) % MOD + ((ll int)3 * seg[i - 2]) % MOD + pow) % MOD;
	}
	pow_max = pow;
}


int calck(int n){

	register int res, p = seg[MAX - 1], pp = seg[MAX - 2];
	register int pow = pow_max;
	for (register int i = 2; i <= n; i++){
		pow = ((ll int)3 * pow) % MOD;
		res = ((ll int)2 * p%MOD + (ll int)3 * pp%MOD + pow) % MOD;
		pp = p;
		p = res;
	}
	return res;

}


int main(){

	preCalc();
	ll int t, n;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		if (n<1)
			printf("%d\n", seg[n]);
		else
			printf("%d\n", calck(n));
	}
	return 0;
}