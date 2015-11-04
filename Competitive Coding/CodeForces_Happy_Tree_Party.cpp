/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/593/problem/D

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

struct edge {
	ll int v, w;
};

vector<pii> xbe;
vector<edge> graph[200001];
int level[200001];


void BFS() {

	queue<int> q;
	q.push(1);
	level[1] = 1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		REP(i, graph[u].size()) {
			if (level[graph[u][i].v]==0) {
				q.push(graph[u][i].v);
				level[graph[u][i].v] = level[u]+1;
			}
		}
	}
}

int main(){

	ll int n, m;
	scanf("%I64d%I64d", &n, &m);
	REP(i, n-1) {
		ll int u, v, x;
		scanf("%I64d%I64d%I64d", &u, &v, &x);
		graph[u].push_back({ v, x });
		graph[v].push_back({ u, x });
		xbe.push_back(mp(u, v));
	}
	BFS();
	REP(i, m) {
		int t;
		scanf("%d", &t);
		if (t==1) {
			ll int a, b, y;
			scanf("%I64d%I64d%I64d", &a, &b, &y);
			vector<int> pa, pb;

		}
		else {
			ll int p, c;
			scanf("%I64d%I64d", &p, &c);
			int u = xbe[p].first, v=xbe[p].second;
			REP(i, graph[u].size()) {
				if (graph[u][i].v==v) {
					graph[u][i].w = c;
				}
			}
			REP(i, graph[v].size()) {
				if (graph[v][i].v==u) {
					graph[v][i].w = c;
				}
			}
		}

	}


	return 0;
}

//Wont Work ~ Not Completed