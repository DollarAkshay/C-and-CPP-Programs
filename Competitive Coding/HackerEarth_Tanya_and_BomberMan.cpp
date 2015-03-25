/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.hackerearth.com/mindsweeper3/algorithm/tanya-and-bomberman/

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

ll int x[100000], y[100000];

int main(){

	ll int t, k, p;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld", &k, &p);
		REP(i, p)
			scanf("%lld%lld", &x[i], &y[i]);
		SORT(x, p);
		SORT(y, p);
		ll int cx = 0, cy = 0;
		REP(i, p){
			if (!i || x[i] != x[i - 1]){
				cx++;
			}
		}

		REP(i, p){
			if (!i || y[i] != y[i - 1]){
				cy++;
			}
		}
		ll int ans = cx < cy ? cx : cy;
		ans *= k;
		printf("%lld\n", ans);
	}
	return 0;
}

//Not Solved