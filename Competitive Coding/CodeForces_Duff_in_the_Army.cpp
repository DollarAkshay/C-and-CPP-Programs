/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/588/problem/E

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


vector<int> graph[100001], people[100001];
int c[100001];
int level[100001];
int parent[100001];

void BFS() {

	queue<int> q;

	q.push(1);
	level[1] = 1;
	parent[1] = -1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		REP(i, graph[x].size()) {
			int neigh = graph[x][i];
			if (!level[neigh]) {
				q.push(neigh);
				level[neigh] = level[x] + 1;
				parent[neigh] = x;
			}
		}
	}

}

void getPeople(int u, int v, int a) {

	set<int> res;
	res.insert(people[u].begin(), people[u].end());
	res.insert(people[v].begin(), people[v].end());
	while (u!=v) {
		if (level[u]>level[v]) {
			u = parent[u];
			res.insert(people[u].begin(), people[u].end());
		}
		else {
			v = parent[v];
			res.insert(people[v].begin(), people[v].end());
		}
	}

	int k = min((ll int)a, (ll int)res.size());
	printf("%d ", k);
	for (auto it = res.begin(); k; it++, k--)
		printf("%d ", *it);
}

int main(){

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	REP(i, n-1) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(v);
	}
	REP(i, m) {
		scanf("%d", &c[i]);
		people[c[i]].push_back(i+1);
	}
	BFS();

	REP(i, q) {
		int u, v, a;
		scanf("%d %d %d", &u, &v, &a);
		getPeople(u, v, a);
		printf("\n");
	}
	return 0;
}

//PreTests Passed