/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/COOK60/problems/KNODES

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

int nodes[100001], k;
vector<int> g[100001];
map<int, int> parent;

void BFS(int s,int n){

	int v[100001], u;
	queue<int> q;

	MS0(v);
	v[s] = 1;
	q.push(s);
	parent[u] = 0;

	while (!q.empty()){
		u = q.front();
		q.pop();
		REP(i, g[u].size()){
			if (v[g[u][i]]==0){
				q.push(g[u][i]);
				v[g[u][i]] = 1;
				parent[g[u][i]] = u;
			}
		}
	}

}


int main(){

	int t, n, q;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n-1){
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].pb(v);
			g[v].pb(u);
		}
		
		scanf("%d", &q);
		REP(qu, q){
			scanf("%d", &k);
			REP(i, k)
				scanf("%d", &nodes[i]);
			parent.clear();
			BFS(nodes[0], n);
			int deg[100001],v[100001];
			MS0(deg);
			MS0(v);
			int path = 1;
			REP(i, k){
				int u = nodes[i];
				while (u!=nodes[0]){
					if (v[u]==0){
						v[u] = 1;
						if (++deg[u]==3){
							path = 0;
							break;
						}
						u = parent[u];
						if (++deg[u]==3){
							path = 0;
							break;
						}
					}
					else{
						u = parent[u];
					}
				}
				if (!path)
					break;
			}
			puts(path?"Yes":"No");
		}
	}
	sp;
	return 0;
}

//~TLE