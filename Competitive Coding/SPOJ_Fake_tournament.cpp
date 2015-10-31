/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/TOUR/

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
#include <functional>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

vector<int> graph[10000];

int bfs(int s) {

	int res=0, u;
	int v[10000];
	queue<int> q;

	MS0(v);
	q.push(s);
	v[s] = 1;
	res++;

	while (!q.empty()) {
		u = q.front();
		q.pop();
		REP(i, graph[u].size()) {
			if (v[graph[u][i]]==0) {
				q.push(graph[u][i]);
				v[graph[u][i]] = 1;
				res++;
			}
		}
	}
	
	return res;

}

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		int set = 0;
		REP(i, n) {
			int w;
			scanf("%d", &w);
			REP(j, w) {
				int v;
				scanf("%d", &v);
				v--;
				graph[v].push_back(i);
			}
		}
		REP(i, n) {
			if (bfs(i)==n)
				set++;
		}
		printf("%d\n", set);
		REP(i, n+2)
			graph[i].clear();
	}
	sp;
	return 0;
}

//Solved