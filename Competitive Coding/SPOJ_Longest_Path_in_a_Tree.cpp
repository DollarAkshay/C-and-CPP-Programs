/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

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

int v[10001];
vector<int> g[10001];
int maxlen=-1,leaf=-1;

void DFS(int s){

	REP(i, g[s].size()){
		if (v[g[s][i]]==0){
			v[g[s][i]] = v[s]+1;
			if (maxlen<v[g[s][i]]-1){
				maxlen = v[g[s][i]]-1;
				leaf = g[s][i];
			}
			DFS(g[s][i]);
		}
	}

}

int main(){

	int n;
	scanf("%d", &n);
	REP(i, n-1){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}

	DFS(1);

	MS0(v);
	v[leaf] = 1;
	maxlen = -1;

	DFS(leaf);

	printf("%d\n", maxlen);
	sp;
	return 0;
}

//Solved