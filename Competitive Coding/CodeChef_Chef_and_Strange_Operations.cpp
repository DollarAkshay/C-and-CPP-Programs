/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/FEB16/problems/STROPR

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007
#define gc getchar

ll int a[100000];

int invert_mod(ll int a) {

	ll int ne = 1, old = 0, q = MOD, r, h;
	ll int pos = 0;
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
	return pos?old:(MOD - old);
}

int main(){

	ll int t, n, x, m;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld %lld %lld", &n, &x, &m);
		x--;
		REP(i, n)
			scanf("%lld", &a[i]);
		ll int res = 0;
		ll int ncr = 1;
		FORD(i, x, 0) {
			res = ((ncr*(a[i]%MOD))%MOD+res)%MOD;
			ncr = ((ncr * (m % MOD) )%MOD * invert_mod(x-i+1))%MOD;
			m++;
		}
		printf("%lld\n", res);
	}
	sp;
	return 0;
}

//Solved :)