
//https://www.hackerearth.com/problem/algorithm/travelling-budget/description/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
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
struct Edge{ int v, w, l; };

vector<Edge> graph[500];

unsigned int cost[501];


void calc(int n){

	FOR(i,1,n)
		cost[i] = -1;
	cost[1] = 0;
	FOR(i,1,4){
		int size = graph[i].size();
		for (int j = 0; j < size; j++){
			Edge e = graph[i][j];
			unsigned int cj = cost[e.v];
			unsigned int ci = cost[i];
			if (ci + e.w < cj)
				cost[e.v] = ci + e.w;
		}
	}
	
}




int main(){

	int t, n, m, B;
	int u, v, c, l;
	int q, x, b;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d%d", &n, &m, &B);
		REP(i, m){
			scanf("%d%d%d%d", &u, &v, &c, &l);
			Edge e;
			e.v = v;
			e.w = c;
			e.l = l;
			graph[u].push_back(e);
		}

		for (int i = 1; i<=m; i++){
			for (int j = 0; j<graph[i].size(); j++){
				printf("Road form city %d to %d costs %d and is %d long\n",
					i, graph[i][j].v, graph[i][j].w, graph[i][j].l);
			}
		}

		calc(n);
		for (int i = 1; i <=m; i++)
			printf("Cost to reach to city %d = %d\n", i, cost[i]);

		scanf("%d", &q);
		REP(i, q){
			scanf("%d%d", &x, &b);

		}

	}
	sp;
	return 0;
}

//Not Solved