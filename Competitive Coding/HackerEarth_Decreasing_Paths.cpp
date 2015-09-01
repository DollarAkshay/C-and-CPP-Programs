/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/september-easy-15/algorithm/decreasing-paths/

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
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

struct point {
	int x, y;
};

point dir[] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int n,ans;
int grid[1000][1000];

void DFS(point s) {

	ans = (ans+1)%MOD;

	REP(i, 4) {
		int x = s.x + dir[i].x, y = s.y + dir[i].y;
		if (x>=0 && x<n && y>=0 && y<n && grid[y][x]<grid[s.y][s.x]) {
			DFS({ x,y });
		}
	}
}

int main(){

	scanf("%d", &n);
	REP(i, n)
		REP(j, n)
			scanf("%d", &grid[i][j]);
	REP(i, n)
		REP(j, n)
			DFS({ j,i });
	printf("%d", ans);
	return 0;
}

//Partially Solved ~ TLE