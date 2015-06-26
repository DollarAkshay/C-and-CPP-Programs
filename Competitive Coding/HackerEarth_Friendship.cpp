/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/exalt1/algorithm/friendship/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

set<int> g[100];

int main(){

	int t, n, m;
	scanf("%d", &t);
	REP(tc, t){
		int f = 0;
		scanf("%d %d", &n, &m);
		REP(i, m){
			int u, v;
			scanf("%d%d", &u, &v);
			g[v].insert(u);
			g[u].insert(v);
			f = max(f, (int)g[v].size());
			f = max(f, (int)g[u].size());
		}
		int comma = 0;
		FOR(i,1,n){
			if (g[i].size() == f){
				if (comma == 0){
					printf("%d", i);
					comma = 1;
				}
				else
					printf(",%d", i);
			}
		}
		printf("\n");
		FOR(i, 1, n)
			g[i].clear();
	}
	return 0;
}

//