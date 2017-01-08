
//http://www.codechef.com/NOV14/problems/CHEFSEG

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

int main(){

	ll int t, x, k;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld", &x, &k);
		int lvl = log2(k) + 1;
		double p = pow(2.0, (double)lvl);
		double ans = 0;

		while (k){
			ans += k % 2 ? 1 / p : -1 / p;
			p /= 2; k /= 2;
		}
		printf("%f\n", ans*x);
	}
	return 0;
}

//Solved