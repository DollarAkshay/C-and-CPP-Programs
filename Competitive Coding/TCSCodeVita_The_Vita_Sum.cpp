/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.tcscodevita.com/CodevitaV5/problemstart.jsp

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
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

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
	return pos?old:(p - old);
}

ll int nCrMOD(int n, int r, int mod) {

	if (n == r || r==0)
		return 1;

	ll int res = 1, i = 1;

	r = n-r>r?n-r:r;

	while (n - r)
		res = ((res*n--) % mod * invert_mod(i++, mod)) % mod;

	return res;
}


int main(){

	int n, k;
	scanf("%d %d", &n, &k);
	ll int res = 0;
	FOR(r, 0, k) {
		res = (res + nCrMOD(n, r, MOD))%MOD ;
		r++;
	}
	printf("%lld\n", res);
	return 0;
}

//