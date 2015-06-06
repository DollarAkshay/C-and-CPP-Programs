/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/MAY15/problems/SETDIFF

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

int p[100015];

void pre(){

	p[0] = 1;
	FOR(i, 1, 100014)
		p[i] = (p[i - 1] * 2) % MOD;
}

int main(){


	pre();
	int a[100015];
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n)
			scanf("%d", &a[i]);
		SORT(a, n);
		ll int ans = 0;
		REP(i, n - 1)
			ans = (ans + (a[n - i - 1] - (ll int)a[i])*(p[n - i - 1] - 1)) % MOD;

		while (ans < 0)
			ans += MOD;
		printf("%lld\n", ans);
	}
	return 0;
}

//