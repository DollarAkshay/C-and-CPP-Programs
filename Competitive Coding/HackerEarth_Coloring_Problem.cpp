/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/coc1/algorithm/coloring-problem/

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

#define MAX 10005

vector<int> G[MAX];

int colour(){

	int paint[MAX], u;

	REP(i, MAX)
		paint[i] = 0;
	queue<int> q;
	q.push(0);
	paint[0] = 1;

	while (!q.empty()){
		u = q.front();
		q.pop();
		int size = G[u].size();
		REP(i, size){
			if (paint[G[u][i]] == 0){
				q.push(G[u][i]);
				paint[G[u][i]] = paint[u] == 1 ? 2 : 1;
			}
			else if (paint[G[u][i]] == paint[u])
				return 0;
		}
	}
	return 1;
}

int main(){

	int t, n, l, u, v;
	scanf("%d", &t);
	REP(tc, t){
		REP(i, MAX)
			G[i].clear();
		scanf("%d%d", &n, &l);
		REP(i, l){
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if (colour())
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");
	}
	sp;
	return 0;
}

//Solved