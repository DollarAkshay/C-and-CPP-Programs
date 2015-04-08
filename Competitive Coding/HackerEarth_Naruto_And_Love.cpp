/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/algoholic-practice/algorithm/naruto-and-love/

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

int p[150000], d[150000];

int main(){

	int t, n,m;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n,&m);
		REP(i, n) scanf("%d", &p[i]);
		REP(i, m) scanf("%d", &d[i]);
		SORT(p, n);
		SORT(d, m);
		ll int ans = -1;
		int v[1500000];
		MS0(v);
		for (int i = 0; i < n; i++){
			int x;
			ll int mi = 2000000000;
			REP(j, m){
				if (v[j] == 0 && abs(p[i] - d[j])<mi){
					mi = abs(p[i] - d[j]);
					x = j;
				}
			}
			ans = max(ans, mi);
			v[x] = 1;
		}
		printf("%lld", ans);
	}
	return 0;
}

//Not Solved