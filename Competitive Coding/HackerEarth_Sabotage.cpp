/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/july-clash-15/algorithm/sabotage-1/

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

struct edge{
	int v, w;
	bool operator<(const edge& rhs) const{
		return w > rhs.w;
	}
};

int v[100001];
int e[100001];

vector<edge> g[100001];

void prims(int n,int m){

	int u = 1;
	vector<int> nodes;
	priority_queue<edge> minedgeheap;

	nodes.pb(u);
	while (nodes.size()<n){
		v[u] = 1;
		REP(j, g[u].size()){
			if (v[g[u][j].v]==0)
				minedgeheap.push(g[u][j]);
		}
		while(v[minedgeheap.top().v]==1)
			minedgeheap.pop();
		u = minedgeheap.top().v;
		nodes.pb(u);
		e[m-minedgeheap.top().w] = 1;
		minedgeheap.pop();
	}

}

int main(){

	int n, m;

	scanf("%d%d", &n, &m);
	FOR(i,1,m){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back({ v, m-i });
		g[v].push_back({ u, m-i });
	}

	prims(n, m);

	printf("%d\n", m-n+1);
	FOR(i, 1, m){
		if (e[i]==0)
			printf("%d\n", i);
	}

	return 0;
}

//Solved