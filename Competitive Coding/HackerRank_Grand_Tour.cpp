/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/101hack24/challenges/grand-tour

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

int dijkstra(int src, int dest, int n){

	int v[100000], d[100000], c = 0, u = src;
	REP(i, n){
		v[i] = 0;
		d[i] = 1001;
	}

	d[u] = 0;

	while (c < n){
		v[u] = 1;
		c++;
		int size = graph[u].size();
		REP(i, size){
			if (d[u] + graph[u][i].w < d[graph[u][i].v] && v[graph[u][i].v]==0){
				d[graph[u][i].v] = d[u] + graph[u][i].w;
			}
		}

		int min = 1001;
		REP(i, n){
			if (d[i] < min){
				min = d[i];
				u = i;
			}
		}

		if (u == dest)
			return d[u];
	}
	return d[dest];
}

int main(){

	int n, m, u, v;
	int s[100000];
	int d[100000];

	scanf("%d", &n);
	REP(i, n)
		scanf("%d", &s[i]);
	REP(i, n){
		int t;
		scanf("%d %d %d", &u, &v, &t);
		graph[u-1].push_back({ v-1, t });
		graph[v - 1].push_back({ u - 1, t });
	}

	ll int answ = 0;
	scanf("%d", &m);

	REP(i, m){
		scanf("%d", &d[i]);
		answ += s[d[i]-1];
		if (i){
			int dist = dijkstra(d[i - 1]-1, d[i]-1, n);
			answ += dist;
		}
	}

	printf("%lld", answ);
	return 0;
}

//Wrong Solution