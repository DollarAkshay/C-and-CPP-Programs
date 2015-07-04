/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.urionlinejudge.com.br/judge/en/challenges/view/51/3

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
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(x) make_pair(x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int a[50][50];

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

int main(){
	int n, m;
	scanf("%d%d",&n, &m);
	getchar();
	REP(i, n){
		REP(j, m){
			if (getchar() == '#')
				a[i][j] = 1;
		}
		getchar();
	}

	int x1, y1, x2, y2;
	while (scanf("%d%d%d%d", &y1, &x1, &y2, &x2) > 0){
		x1--; x2--; y1--; y2--;
		int wall = 0;
		FOR(i, y1, y2){
			FOR(j, x1, x2){
				if (a[i][j] == 1)
					wall++;
			}
		}
		printf("%lld\n", nCrMOD((x2 - x1 + 1)*(y2 - y1 + 1), wall, MOD) - 1);
	}
	return 0;
}

//