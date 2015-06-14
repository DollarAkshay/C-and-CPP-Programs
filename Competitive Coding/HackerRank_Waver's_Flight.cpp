/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/indeed-prime-challenge/challenges/waver1

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

vector<Edge> graph[100000];

int leaf[100000];

int dijkstra(int s, int n){

	int d[100000], v[100000], u, c = 0;
	FOR(i, 1, n){
		v[i] = 0;
		d[i] = 1 << 30;
	}
	u = s;
	d[u] = 0;
	v[u] = 1;
	c++;
	while (c < n){
		REP(i, graph[u].size()){
			if (v[graph[u][i].v] == 0 && d[u] + graph[u][i].w < d[graph[u][i].v]){
				d[graph[u][i].v] = d[u] + graph[u][i].w;
			}
		}

		int min = 1 << 30;

		FOR(i, 1, n){
			if (!v[i] && d[i] < min){
				min = d[i];
				u = i;
			}
		}
		c++;
		v[u] = 1;
	}
	int min = 1 << 30;
	FOR(i, 1, n){
		if (leaf[i] && d[i] < min)
			min = d[i];
	}
	return min;

}


int main(){

	int n, s, k;
	scanf("%d%d%d", &n, &s, &k);
	REP(i, n - 1){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	FOR(i,1,n){
		if (graph[i].size() == 1)
			leaf[i] = 1;
	}

	REP(i, s){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	FOR(i, 1, n){
		int dist = 0;
		if (!leaf[i])
			dist = dijkstra(i, n);
		printf("%d\n", dist);
	}

	return 0;
}

//