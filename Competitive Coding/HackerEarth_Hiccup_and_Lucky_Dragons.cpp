/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/hiccup-and-lucky-dragons/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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


ll int invert_mod(ll int a, ll int p) {
	ll int ne = 1, old = 0, q = p, r, h;
	int pos = 0;
	while (a > 0) {
		r = q%a;
		q = q / a;
		h = q*ne + old;
		old = ne;
		ne = h;
		q = a;
		a = r;
		pos = !pos;
	}
	return pos ? old : (p - old);
}

int main(){

	ll int t, n,m;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld", &n,&m);
		ll int e = n % 2 ? (n - 1)/2 % m : (n - 2)/2 % m;
		n %= m;
		ll int res,r1,r2,r3,r4,r5;
		r1 = e*n*n;
		r2 = n*e;
		r3 = 2 * n*e*(e + 1);
		r4 = 2 * e*(e + 1)*(2 * e + 1) / 3;
		r5 = e*(e + 1);
		res = (r1%m + r2%m - r3%m + r4%m - r5%m) / 2;
		printf("%lld\n", res%m);
	}
	sp;
	return 0;
}

//Not Solved