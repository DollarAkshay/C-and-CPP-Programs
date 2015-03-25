/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/dexter-and-mandark-1/

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

unsigned long long invert_mod(unsigned long long a, unsigned long long p) {
	unsigned long long ne = 1, old = 0, q = p, r, h;
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


ll int nCrMod(ll int n,ll int r,ll int mod){
	if (n == r)
		return 1;
	ll int x = 1, i = 1;
	r = n - r>r ? n - r : r;
	while (n - r)x = ((x*n--) % mod * invert_mod(i++,mod))%mod;
	return x;
}

ll int powMod(int a, int n, int mod){

	ll int res = 1;
	while (n--)
		res = (res*a)%mod;
	return res;

}

int main(){

	int t, n,m;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &m);
		int rounds = n -= m;
		int seq = m + 1;
		ll int ans = 1;
		while (rounds>0){
			int power = rounds / seq;
			int a = powMod(seq, power, MOD);
			int b = powMod(2, rounds%seq, MOD);
			int res = a*b%MOD;
			ans += res;
			rounds-=m;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

//Partially Solved