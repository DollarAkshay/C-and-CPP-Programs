/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/JUNE15/problems/CHPLGNS

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
#define gc getchar_unlocked

struct point{
	int x;
	int y;
};

struct poly{
	int n;
	int m;
	vector<point> pts;
};

poly p[100000];

bool compare1(poly l, poly r){
	return ((l.pts[0].x < r.pts[0].x) || (l.pts[0].x == r.pts[0].x && l.pts[0].y < r.pts[0].y));
}

bool compare2(point l, point r){
	return ((l.x < r.x) || (l.x == r.x && l.y < r.y));
}

int main(){

	int t, n,m;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n){
			p[i].n = i;
			scanf("%d", &m);
			p[i].m = i;
			REP(j, m){
				int x, y;
				scanf("%d%d", &x, &y);
				p[i].pts.push_back({ x, y });
			}
			sort(begin(p[i].pts), begin(p[i].pts) + m, compare2);
		}
		sort(begin(p), begin(p) + n, compare1);
		int ans[100000];
		REP(i, n)
			ans[p[i].n] = n - i - 1;
		REP(i, n){
			printf("%d ", ans[i]);
			p[i].pts.clear();
		}
	}
	return 0;
}

//Solved