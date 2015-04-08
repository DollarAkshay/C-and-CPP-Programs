/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/rani-and-ladders-2/

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
#include <queue>

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

#define MAX 160000

vector<Edge>adj[MAX+1];
int dist[MAX + 1], visited[MAX + 1];
int lad[MAX + 1];

void initMatrix(int n){
	FOR(i, 1, n) 
		lad[i] = 0;
	FOR(i,1,n){
		FOR(j, 2, 12){
			if (j + i <= n){
				Edge e = { i + j, 1 };
				adj[i].push_back(e);
			}
		}
	}
}

void bfs(int n){

	queue<int> q;
	int u;

	FOR(i, 1, n){
		visited[i] = 0;
		dist[i] = 0;
	}
	q.push(1);
	visited[1] = 0;

	while (!q.empty()){
		u = q.front();
		q.pop();
		int size = adj[u].size();
		REP(i, size){
			if (visited[adj[u][i].v]==0){
				q.push(adj[u][i].v);
				visited[adj[u][i].v] = 1;
				dist[adj[u][i].v] = dist[u] + adj[u][i].w;
				if (lad[adj[u][i].v]){
					q.back() = lad[adj[u][i].v];
					visited[lad[adj[u][i].v]] = 1;
					dist[lad[adj[u][i].v]] = dist[adj[u][i].v];
				}
				if (adj[u][i].v == n || lad[adj[u][i].v]==n)
					return ;
			}
		}
	}
}



int main(){


	int t, n,l,b,u;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &l);
		initMatrix(n);
		REP(i, l){
			scanf("%d%d", &b, &u);
			lad[b] = u;
		}
		bfs(n);
		printf("%d\n", dist[n]);
	}
	return 0;
}

//90% Works