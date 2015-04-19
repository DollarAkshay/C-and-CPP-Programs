/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/APRIL15/problems/CSEQ

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
#define MOD 1000003
#define gc getchar_unlocked


struct Edge{ int v, w; };

int invert_mod(int a, int p) {
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


ll int nCrMod(int n, int r, int mod){
	if (n == r)
		return 1;
	ll int x = 1, i = 1;
	r = n - r>r ? n - r : r;
	while (n - r){
		x = ((x*n--) % mod * invert_mod(i++, mod)) % mod;
		if (x == 0) 
			return 0;
	}
	return x;
}

int main(){

	int t, n, l, r;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d%d", &n, &l, &r);
		int m = r - l + 1;
		int x = max(n, m);
			printf("%lld\n", nCrMod(n + m, m, MOD) - 1);
	}
	return 0;
}

// 