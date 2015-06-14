/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/flavored-june/algorithm/a-team/

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
struct Edge{ int v, w; };

struct point{
	int x, y;
};

int onSegment(point p1, point p2, point r){

	if (r.x <= max(p1.x, p2.x) && r.x >= min(p1.x, p2.x) &&
		r.y <= max(p1.y, p2.y) && r.y >= min(p1.y, p2.y))
		return 1;
	else
		return 0;
}

int orientation(point p1, point p2, point p3){

	int dir = (p2.y - p1.y)*(p3.x - p2.x) - (p3.y - p2.y)*(p2.x - p1.x);
	if (dir == 0)
		return 0;
	return dir > 0 ? 1 : -1;
}

int intersect(point p1, point q1, point p2){

	point q2 = { 0, 0 };
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4)
		return 1;

	if (o1 == 0 && onSegment(p1, q1, p2))
		return 1;
	if (o2 == 0 && onSegment(p1, q1, q2))
		return 1;
	if (o3 == 0 && onSegment(p2, q2, p1))
		return 1;
	if (o4 == 0 && onSegment(p2, q2, q1))
		return 1;
	return 0;
}

int main(){

	int t, n;
	point wal1, wal2, crim;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d%d%d%d%d", &wal1.x, &wal1.y, &wal2.x, &wal2.y, &crim.x, &crim.y);
		puts(intersect(wal1, wal2, crim) ? "NO" : "YES");

	}
	return 0;
}

//