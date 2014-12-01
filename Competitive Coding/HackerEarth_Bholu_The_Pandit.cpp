/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.hackerearth.com/december-easy-challenge-1/algorithm/bholu-the-pandit-1/

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

int gcd(int a, int b){
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

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

int main(){

	int t, a,b,c,d,res;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d%d", &a,&b,&c);
		res = gcd(a, b);
		res = gcd(res, c);

		ll int vols = res;
		vols = (vols*res) % MOD;
		vols = (vols*res) % MOD;

		ll int volb = a;
		volb = (volb*b) % MOD;
		volb = (volb*c) % MOD;
		printf("%d %d\n",res, (volb * invert_mod(vols, MOD)) % MOD);
	}
	return 0;
}

//Solved