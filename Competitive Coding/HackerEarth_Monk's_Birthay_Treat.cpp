/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/monks-birthday-treat/

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

vector<int> g[1000];
int v[1000];

int dfs(int s){

	int res = 1;
	v[s] = 1;
	REP(i, g[s].size()){
		if (!v[g[s][i]])
			res+=dfs(g[s][i]);
	}
	return res;
}

int main(){

	int n, m;
	scanf("%d%d", &n ,&m);
	REP(i, m){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		g[u].pb(v);
	}
	int ans=n;
	REP(i, n){
		MS0(v);
		ans = min(ans, dfs(i));
	}
	printf("%d\n", ans);
	return 0;
}

//Solved