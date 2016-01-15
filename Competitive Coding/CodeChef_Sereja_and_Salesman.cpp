/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/JAN16/problems/SEAKAM

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
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int n, m;

int v[100000];
set<pair<int, int>> removed;

set<vector<int>> all;

bool calc[1000][1000];
ll int DP[1000][1000];

ll int DFS(int s, int k) {

	if (calc[s][k])
		return DP[s][k];

	ll int res = 0;

	v[s] = 1;

	if (k==0) {
		res = 1;
	}
	else {
		REP(i, n) {
			if (v[i]==0 && removed.find(mp(s, i))==removed.end()) {
				res = (res + DFS(i, k-1))%MOD;
			}
		}
	}

	v[s] = 0;

	DP[s][k] = res;
	calc[s][k] = true;
	return res;

}

int main() {

	pre();
	int t;
	scanf("%d", &t);
	REP(tc, t) {
		scanf("%d%d", &n, &m);

		REP(i, m) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--; v--;
			removed.insert(mp(u, v));
			removed.insert(mp(v, u));
		}
		ll int res = 0;
		REP(i, n)
			res = (res + DFS(i, n-1))%MOD;
		printf("%lld\n", res);

		removed.clear();
		MS0(calc);
	}
	sp;
	return 0;
}

//