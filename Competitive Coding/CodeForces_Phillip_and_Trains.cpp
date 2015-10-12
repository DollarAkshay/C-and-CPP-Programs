/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/586/problem/D

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

struct point {
	int x, y;
};


char graph[3][50];

bool DFS(point s,int n,int train) {

	if (graph[s.y][s.x]!='.' || s.x>=n || s.y<0 || s.y>2)
		return false;

	if (s.x==n-1 && graph[s.y][s.x]=='.')
		return true;


	if (train==0) {
		return DFS({ s.x+1, s.y }, n, (train+1)%4);
	}
	if (train==1) {
		bool dir[3];
		dir[0] = DFS({ s.x, s.y-1 }, n, (train+1)%4);
		if (dir[0])
			return true;
		dir[1] = DFS({ s.x, s.y }, n, (train+1)%4);
		if (dir[1])
			return true;
		dir[2] = DFS({ s.x, s.y+1 }, n, (train+1)%4);
		if (dir[2])
			return true;
		return false;
	}
	else {
		return DFS({ s.x+1, s.y}, n, (train+1)%4 );
	}

}

int main(){

	int n;
	scanf("%d", &n);
	REP(i, n) {
		int k, t;
		point start;
		scanf("%d %d", &k, &t);
		scanf("%s", graph[0]);
		scanf("%s", graph[1]);
		scanf("%s", graph[2]);

		if (graph[0][0]=='s') 
			start = { 0, 0 };
		else if (graph[1][0]=='s')
			start = { 0, 1 };
		else if (graph[2][0]=='s')
			start = { 0, 2 };
		else
			assert(1==0);

		graph[start.y][start.x] = '.';

		puts(DFS(start, k, 0)?"YES":"NO");
	}
	return 0;
}

//