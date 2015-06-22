/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

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
struct point{
	int x, y;
};

int graph[500][500], isGate[500], n;


void bfs(int s){

	int v[500],u;
	MS0(v);
	queue<int> q;
	v[s] = 1;
	q.push(s);

	while (!q.empty()){
		u = q.front();
		q.pop();
		REP(i, n){
			if (!v[i] && graph[u][i]){
				v[i] = 1;
				q.push(i);
				if (isGate[i]){
					graph[u][i] = 0;
					graph[i][u] = 0;
					printf("%d %d\n", u, i);
					return;
				}
			}
		}
	}

}

int main(){

	int e,g,agent;
	scanf("%d%d%d", &n,&e,&g);
	REP(i, e){
		int u, v;
		scanf("%d%d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	REP(i, g){
		int x;
		scanf("%d", &x);
		isGate[x] = 1;
	}
	while (1){
		scanf("%d", &agent);
		bfs(agent);
	}
	return 0;
}

//