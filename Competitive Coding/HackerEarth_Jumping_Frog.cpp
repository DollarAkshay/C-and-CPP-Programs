
//http://www.hackerearth.com/CDZV10/algorithm/jumping-frog/

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
#define gc getchar
struct Edge{ int v, w; };

int a[100000],n;
vector<int> graph[100000];
int check[100000],dist[100000];


void scanint(int &x)
{
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

int shortestPath(int s,int e){

	MS0(check);
	queue<int> q;
	int i;

	for (i = 0; i < n; i++)
		dist[i] = -1;

	dist[s] = 0;
	check[s] = 1;
	q.push(s);

	while (!q.empty()){
		i = q.front();
		q.pop();
		for (int j = 0; j < graph[i].size(); j++){
			if (check[graph[i][j]] == 0){
				dist[graph[i][j]] = dist[i] + 1;
				check[graph[i][j]] = 1;
				q.push(graph[i][j]);
				if (graph[i][j]==e)
					return dist[e];
			}
		}
	}
	return dist[e];
}

void printGraph(){

	printf("\n");
	REP(i, n){
		int size = graph[i].size();
		printf("From %d you can jump to :", i);
		REP(j, size)
			printf(" %d", graph[i][j]);
		printf("\n");
	}

}

int main(){

	int q,s,e,m;
	scanint(n);
	REP(i, n){
		scanint(a[i]);
		if (i)
			graph[i].push_back(i - 1);
		int col = a[i];
		REP(j, i){
			if (a[j] == col){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}


	//solveGraph();
	//printGraph();

	scanint(q);
	REP(i, q){
		scanint(s);
		scanint(m);
		scanint(e);
		int a = shortestPath(s, m);
		if (a == -1){
			printf("-1\n");
		}
		else{
			int b = shortestPath(m, e);
			if (b != -1)
				printf("%d\n", a + b);
			else
				printf("-1\n");
		}	
	}
	return 0;
}

// Partially Solved 70/100 ~ TLE

