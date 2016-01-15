/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/JAN16/problems/DEVPERF

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

int a[100000];
int t, b, l, r;

char grid[1000][1001];

int maxDist(int n, int m, int x, int y) {

	int res = -1;

	REP(i, n) {
		REP(j, m) {
			if (grid[i][j]=='*') {
				int dx = abs(j-x), dy = abs(i-y);
				res = max(res, min(dx,dy)+abs(dx-dy));
			}
		}
	}
	return res;

}

int main(){

	int tx, n, m, x, y, ans;
	scanf("%d", &tx);
	REP(tc, tx){
		scanf("%d%d", &n, &m);
		t = b = r = -1;
		l = 1001;
		REP(i, n) {
			scanf("%s", grid[i]);
			char *cp = strchr(grid[i], '*');
			if (cp) {
				if (t<0)
					t = i;
				if(t>=0)
					b = i;
				l = min(cp-grid[i], l);
				r = max(strrchr(grid[i], '*')-grid[i], r);
			}
		}


		x = (l+r)/2;
		y = (t+b)/2;

		printf("%d\n", 1+maxDist(n,m,x,y));
	}
	sp;
	return 0;
}

//Solved