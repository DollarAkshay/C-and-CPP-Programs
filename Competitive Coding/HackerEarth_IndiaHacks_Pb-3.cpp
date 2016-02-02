/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/indiahacks-code-mania-9/algorithm/center-in-mass-2/

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

int main() {

	int test, n;
	scanf("%d", &test);
	REP(tc, test) {
		scanf("%d", &n);
		double cx = 0, cy = 0, cz = 0;
		double cvx = 0, cvy = 0, cvz = 0;
		REP(i, n) {
			int x, y, z;
			int vx, vy, vz;
			scanf("%d%d%d %d%d%d", &x, &y, &z, &vx, &vy, &vz);
			cx += x;
			cy += y;
			cz += z;

			cvx += vx;
			cvy += vy;
			cvz += vz;
		}

		cx /= n;
		cy /= n;
		cz /= n;

		cvx /= n;
		cvy /= n;
		cvz /= n;

		double t = -(cx*cvx + cy*cvy + cz*cvz)/(cvx*cvx + cvy*cvy + cvz*cvz);

		if (t<0)
			t = 0;

		double px, py, pz;
		px = cx + cvx*t;
		py = cy + cvy*t;
		pz = cz + cvz*t;

		double dist = sqrt(px*px + py*py + pz*pz);
		printf("Case #%d: %.8lf %.8lf\n", tc+1, dist, t);
	}
	sp;
	return 0;
}

//Solved