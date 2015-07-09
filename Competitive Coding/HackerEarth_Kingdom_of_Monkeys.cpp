/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/kingdom-of-monkeys/

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
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

ll int a[100001];
vector<int> g[100001];

ll int DFS(int s){

	ll int res = 0;
	res += a[s];
	a[s]=-1;
	REP(i, g[s].size()){
		if (a[g[s][i]]!=-1)
			res += DFS(g[s][i]);
	}
	return res;
}

int main(){

	int t, n, m;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &m);
		REP(i, m){
			int u, v;
			scanf("%d%d", &u, &v);
			u--;v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		REP(i, n)
			scanf("%lld", &a[i]);
		ll int gold = 0 ;
		REP(i, n){
			if (a[i]!=-1)
				gold = max(gold,DFS(i));
		}
		printf("%lld\n",gold);
		REP(i,n)
			g[i].clear();
	}
	return 0;
}

//Solved