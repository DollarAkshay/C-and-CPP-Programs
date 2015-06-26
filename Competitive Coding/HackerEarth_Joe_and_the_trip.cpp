/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/exalt1/algorithm/joe-and-the-trip/

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
#define MOD 1000000007

#define MAX 100000

char p[MAX];
int cp[MAX];

void seiv(){
	ll int i, j, lim = sqrt(MAX);
	MS1(p);
	p[0] = p[1] = 0;
	for (i = 2; i <= lim; i++){
		if (p[i]){
			for (j = i*i; j < MAX; j += i)
				p[j] = 0;
		}
	}
	FOR(i, 2, MAX - 1)
		cp[i] = p[i] ? cp[i - 1] + 1 : cp[i - 1];
}

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

ll int nCrMOD(int n, int r, int mod){
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

ll int factMOD(int n){

	ll int f = 1;
	REP(i, 1, n)
		f = (f*i) % MOD;
	return f;
}

ll int nPrMOD(int n, int r, int mod){

	if (n == r)
		return 1;
	return (factMOD(n)*invert_mod(factMOD(n - r), mod)) % MOD;
}

int powMOD(int b, int e){

	int res = 1;
	while (e--)
		res = ((ll int)res*b) % MOD;
	return res;

}

ll int calc(int n, int m){

	return ((ll int)cp[m] * nPrMOD(m - 1, n - 1, MOD)) % MOD;

}



int main(){

	seiv();
	int t, n, m;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d %d", &n, &m);
		printf("%lld\n", calc(n, m));
	}
	return 0;
}

//