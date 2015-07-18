/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/BITMAP/

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

struct point{
	int x, y;
};

point dir[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int main(){

	int t, n, m;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &m);
		int a[200][200],v[200][200];
		queue<point> q;
		MS0(v);
		REP(i, n){
			getchar();
			REP(j, m){
				a[i][j] = getchar()-'0';
				if (a[i][j]){
					q.push({ j, i });
					v[i][j] = 1;
				}
			}
		}

		while (!q.empty()){
			point u = q.front();
			q.pop();
			REP(i, 4){
				int dx = dir[i].x, dy = dir[i].y;
				if (u.x+dx>=0 && u.x+dx<m &&
					u.y+dy>=0 && u.y+dy<n &&
					v[u.y+dy][u.x+dx]==0){
					v[u.y+dy][u.x+dx] = 1 + v[u.y][u.x];
					q.push({ u.x+dx, u.y+dy });
				}
			}
		}
		REP(i, n){
			REP(j, m)
				printf("%d ", v[i][j]-1);
			printf("\n");
		}
	}
	sp;
	return 0;
}

//Solved