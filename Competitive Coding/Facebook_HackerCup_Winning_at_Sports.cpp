/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.facebook.com/hackercup/problems.php?pid=688426044611322&round=344496159068801

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

ll int nCrMod(ll int n, ll int r, ll int mod){
	if (n == r)
		return 1;
	ll int x = 1, i = 1;
	r = n - r>r ? n - r : r;
	while (n - r)x = ((x*n--) % mod * invert_mod(i++, mod)) % mod;
	return x;
}

int main(){

	FILE *fp = fopen("op.txt", "w");
	ll int t, a,b;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld-%lld", &a,&b);
		int ans1 = ((nCrMod(a + b, b, MOD) * ((a - b) % MOD))%MOD * invert_mod(a + b, MOD))%MOD ;
		int ans2 = (nCrMod(2 * b, b, MOD) * invert_mod(b + 1, MOD)) % MOD;
		printf("Case #%d: %d %d\n", tc + 1, ans1, ans2);
		fprintf(fp,"Case #%d: %d %d\n", tc + 1, ans1, ans2);
	}
	fclose(fp);
	sp;
	return 0;
}

//