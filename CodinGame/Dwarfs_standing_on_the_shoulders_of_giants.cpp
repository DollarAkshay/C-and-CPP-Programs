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
#define DB(s,x) fprintf(stderr,s,x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
struct point{
	int x, y;
};

vector<int> graph[100000];

char influenced[100000];

int bfs(int s){

	queue<pair<int, int>> q;
	pair<int, int> u;
	int ans=1, v[100000];
	MS0(v);

	v[s] = 1;
	q.push(make_pair(s,1));

	while (!q.empty()){
		u = q.front();
		q.pop();
		int size = graph[u.first].size();
		REP(i, size){
			if (!v[graph[u.first][i]]){
				ans = max(ans, u.second + 1);
				q.push(make_pair(graph[u.first][i], u.second + 1));
				v[graph[u.first][i]] = 1;
			}
		}
	}
	return ans;

}


int main(){

	int n,x,y,last=-1;
	scanf("%d", &n);
	REP(i, n){
		scanf("%d%d", &x, &y);
		graph[x].push_back(y);
		influenced[y] = 1;
		last = max(x, last);
		last = max(y, last);
	}

	int ans = 0;
	FOR(i, 0, last){
		if (!influenced[i] && graph[i].size() > 0)
			ans = max(ans, bfs(i));
	}

	printf("%d\n",ans);
	return 0;
}

//Solved