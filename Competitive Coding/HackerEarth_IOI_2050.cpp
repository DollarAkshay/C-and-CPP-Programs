/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.hackerearth.com/capillary-hiring-challenge/algorithm/ioi-2050-2/description/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <list>
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

struct Edge{
	int v, w;
};

struct sEdge {
	int u, v, w;
};


vector<Edge> graph[100000];
vector<Edge> MSP[100000];
int visited[100000];

void solve_graph(int n){

	MS0(visited);
	vector<int> node;
	vector<sEdge> prim;
	sEdge e;

	node.push_back(1);
	visited[1] = 1;

	while (1){
		int min = 1000001;
		REP(i, node.size()){
			REP(j, graph[node[i]].size()){
				if (graph[node[i]][j].w < min && visited[graph[node[i]][j].v] == 0){
					e = { node[i], graph[node[i]][j].v, graph[node[i]][j].w };
					min = graph[node[i]][j].w;
				}
			}
		}
		if (min == 1000001)
			break;
		prim.push_back(e);
		visited[e.v] = 1;
		node.push_back(e.v);
	}

	REP(i, prim.size()){
		Edge ed = { prim[i].v, prim[i].w };
		MSP[prim[i].u].push_back(ed);
		ed.v = prim[i].u;
		MSP[prim[i].v].push_back(ed);
	}
}

int dfs(int a, int b){

	stack<int> s;

	MS0(visited);
	s.push(a);
	visited[a] = 1;
	int dist = 0;
	while (!s.empty()){
		int node = s.top(), next = -1;
		REP(i, MSP[node].size()){
			if (visited[MSP[node][i].v] == 0){
				next = MSP[node][i].v;
				dist += MSP[node][i].w;
				if (next == b)
					return dist;
				break;
			}
		}
		if (next == -1){
			int del = s.top();
			s.pop();
			if (s.empty())
				return dist;
			int from = s.top();
			REP(i, MSP[from].size()){
				if (MSP[from][i].v == del){
					dist -= MSP[from][i].w;
					break;
				}
			}
		}
		else{
			visited[next] = 1;
			s.push(next);
		}
	}
	return dist;
}

int main(){

	int t, n, p, q, u, v, d;
	scanf("%d", &t);
	REP(tc, t){

		printf("Case: %d\n", tc + 1);
		scanf("%d%d%d", &n, &p, &q);
		REP(i, p){
			scanf("%d%d%d", &u, &v, &d);
			Edge e = { v, d };
			graph[u].push_back(e);
			e.v = u;
			graph[v].push_back(e);
		}
		solve_graph(n);
		REP(i, q){
			scanf("%d%d", &u, &v);
			printf("%d\n", dfs(u, v));
		}
		REP(i, n) graph[i].clear();
		REP(i, n) MSP[i].clear();
		MS0(visited);
	}
	sp;
	return 0;
}

//TLE