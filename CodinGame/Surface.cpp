/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/16258864cbd30045d121818fc0f5c3d84ad6a05

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
#define DB(s,x) fprintf(stderr,s,x);
#define MS(x,n) memset(x,n,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

struct point{
	int x, y;
};

int w, h;
int ans[1001];
point dir[4] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };

char area[10000][10000];
int v[10000][10000];

int BFS(point s,int k){
	
	int c = 0;
	if (area[s.y][s.x]=='O'){

		point u;
		queue<point> q;

		q.push(s);
		v[s.y][s.x] = k;

		while (!q.empty()){
			point u = q.front();
			q.pop();

			if (area[u.y][u.x]=='O')
				c++;

			REP(i, 4){
				int dx = dir[i].x, dy = dir[i].y;
				if (u.x+dx>=0 && u.x+dx<w &&
					u.y+dy>=0 && u.y+dy<h &&
					area[u.y+dy][u.x+dx]=='O' && v[u.y+dy][u.x+dx]==0){
					q.push({ u.x+dx, u.y+dy });
					v[u.y+dy][u.x+dx] = k;
				}
			}
		}
	}
	else
		v[s.y][s.x] = k;
	return c;

}

int main(){

	int n;
	scanf("%d%d", &w, &h);

	REP(i, h)
		scanf("%s", area[i]);
	scanf("%d", &n);
	REP(i, n){
		int x, y;
		scanf("%d%d", &x, &y);
		if (v[y][x])
			printf("%d\n", ans[v[y][x]]);
		else{
			ans[i+1] = BFS({ x, y }, i+1);
			printf("%d\n", ans[i+1]);
		}
	}
	
	return 0;
}

//Solved