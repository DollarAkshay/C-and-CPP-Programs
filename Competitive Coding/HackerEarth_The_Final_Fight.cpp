/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/july-easy-15/algorithm/the-final-fight-6/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

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
#define MOD 1000000009


ll int invert_mod(ll int a, ll int p) {
	ll int ne = 1, old = 0, q = p, r, h;
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
	return pos ? old : (p - old);
}

ll int nCrMOD(ll int n, ll int r, ll int mod){

	if (n == r)
		return 1;

	ll int x = 1, i = 1;

	while (n - r){
		x = ((x*n--) % mod * invert_mod(i++, mod)) % mod;
		if (x == 0)
			return 0;
	}
	return x%MOD;
}

int main(){

	ll int n, res;
	scanf("%lld", &n);

	if (n <= 1)
		res = 1;
	else
		res = (nCrMOD(2 * n, n, MOD)*invert_mod(n + 1, MOD)) % MOD;

	printf("%lld\n", res);
	sp;
	return 0;
}

//Solved