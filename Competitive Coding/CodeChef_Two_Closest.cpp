/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/LTIME34/problems/PAIRCLST

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



struct edge {
	int v, w;
};

class compare {
public:
	bool operator()(edge& l, edge& y) {
		return l.w > y.w;
	}
};

bool is_sp[100001];
int s[10001];

vector<edge> graph[100001];

int dijkstra(int n, int s) {

	priority_queue<edge, std::vector<edge>, compare> q;

	int dist[100001];
	FOR(i, 1, n)
		dist[i] = INT32_MAX;

	dist[s] = 0;
	q.push({ s, 0 });

	while (!q.empty()) {

		edge e = q.top();
		q.pop();
		int u = e.v;
		if (is_sp[u] && u!=s)
			return e.w;

		REP(i, graph[u].size()) {
			int v = graph[u][i].v, w = graph[u][i].w;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u]+w;
				q.push({ v, dist[v] });
			}
		}
	}

	return INT32_MAX;
}

int main(){

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	REP(i, k) {
		scanf("%d", &s[i]);
		is_sp[s[i]] = true;
	}

	REP(i, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	int min_d = INT32_MAX;

	REP(i, k) 
		min_d = min(min_d, dijkstra(n, s[i]));

	printf("%d\n", min_d);

	sp;
	return 0;
}

//Solved :O :O :O :O :O :O :O :O :O :O :O :O :O :O :O :O Cant beleive it. Heart is beating so Damn Fast