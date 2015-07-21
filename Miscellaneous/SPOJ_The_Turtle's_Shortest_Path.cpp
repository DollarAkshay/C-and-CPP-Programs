/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/TSHPATH/

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
#define MAX 200001
#define gc getchar

struct edge{
	int v, w;
};


void scanint(int &x){
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

vector<int> ans[10000];
vector<edge> g[10000];

class compare{
public:
	bool operator()(edge& l, edge& y){
		return l.w > y.w;
	}
};

void dijkstra(int n, int s){

	priority_queue<edge, std::vector<edge>, compare> q;

	REP(i, n)
		ans[s].pb(MAX);


	ans[s][s] = 0;
	q.push({ s, 0 });
	int u = s, c = 0;

	while (!q.empty()){
		edge e = q.top();
		q.pop();
		int u = e.v;
		if (e.w<=ans[s][u]){
			REP(i, g[u].size()){
				if (ans[s][u]+g[u][i].w<ans[s][g[u][i].v]){
					ans[s][g[u][i].v] = ans[s][u]+g[u][i].w;
					q.push({ g[u][i].v, ans[s][g[u][i].v] });
				}
			}
		}
	}
}


int main(){

	char c[11];
	int t, n, m;
	scanint(t);
	REP(tc, t){

		map<string, int> city;

		scanint(n);
		REP(i, n){
			scanf("%s", c);
			city[c] = i;
			scanint(m);
			REP(j, m){
				int w, v;
				scanint(v);
				scanint(w);
				g[i].push_back({ v-1, w });
			}
		}
		int q;
		scanf("%d", &q);
		REP(i, q){
			char c1[11], c2[11];
			scanf("%s %s", c1, c2);
			int start = city[c1], end = city[c2];
			if (ans[start].size()==0)
				dijkstra(n, start);
			printf("%d\n", ans[start][end]);
		}
		REP(i, n){
			ans[i].clear();
			g[i].clear();
		}

	}
	sp;
	return 0;
}

//Solved