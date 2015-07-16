/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/PT07Y/

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

bool isTree = true;
int parent[10001],v[10001];
vector<int> g[10001];


void DFS(int s){

	v[s] = 1;
	REP(i, g[s].size()){
		if (v[g[s][i]]==1 && parent[s]!=g[s][i])
			isTree = false;
		else if (v[g[s][i]]==0){
			parent[g[s][i]] = s;
			DFS(g[s][i]);
		}
	}
}

int connected(int n){

	int con = 1;
	FOR(i,1,n){
		if (v[i]==0){
			con = 0;
			break;
		}
	}
	return con;
}


int main(){

	
	int n, m;
	scanf("%d%d", &n, &m);

	if (n-1==m){
		REP(i, m){
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].pb(v);
			g[v].pb(u);
		}
		DFS(1);
		if (isTree && !connected(n))
			isTree = false;
	}
	else
		isTree = false;

	puts(isTree?"YES":"NO");

	sp;
	return 0;
}

//Solved