/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/672/problem/C

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
	ll int x, y;
};

point bottle[100005];
double distA[100005], distB[100005], distR[100005];

double dist(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main(){

	point a, b, r;
	
	pair<ll int, double> bestA, bestB;
	bestA = mp(-1, -1000000000000000000);
	bestB = mp(-1, -1000000000000000000);

	scanf("%I64d%I64d %I64d%I64d %I64d%I64d", &a.x, &a.y, &b.x, &b.y, &r.x, &r.y);

	ll int n;
	scanf("%I64d", &n);

	REP(i, n) {
		scanf("%I64d %I64d", &bottle[i].x, &bottle[i].y);
		distA[i] = dist(a, bottle[i]) + dist(bottle[i], r);
		distB[i] = dist(b, bottle[i]) + dist(bottle[i], r);
		distR[i] = dist(r, bottle[i]) + dist(bottle[i], r);

		if ((distR[i]-distA[i]) > bestA.second) {
			bestA = mp(i, (distR[i]-distA[i]));
		}

		if ((distR[i]-distB[i]) > bestB.second) {
			bestB = mp(i, (distR[i]-distB[i]));
		}
	}


	double result = 0;

	if (bestA.second < 0 && bestB.second<0) {
		if (bestA.second>bestB.second) {
			result = distA[bestA.first];
			REP(i, n) {
				if (i!=bestA.first)
					result += distR[i];
			}
		}
		else {
			result = distB[bestB.first];
			REP(i, n) {
				if (i!=bestB.first)
					result += distR[i];
			}
		}
	}
	else if (bestA.second > 0 && bestB.second < 0) {
		result = distA[bestA.first];
		REP(i, n) {
			if (i!=bestA.first)
				result += distR[i];
		}
	}
	else if (bestA.second < 0 && bestB.second > 0) {
		result = distB[bestB.first];
		REP(i, n) {
			if (i!=bestB.first)
				result += distR[i];
		}
	}
	else {

		if (bestA.first == bestB.first) {

			if (bestA.second > bestB.second) {
				bestB = mp(-1, -1000000000000000000);
				REP(i, n) {
					if (i!=bestA.first && ((distR[i]-distB[i]) > bestB.second)) {
						bestB = mp(i, (distR[i]-distB[i]));
					}
				}
			}

			else {
				bestA = mp(-1, -1000000000000000000);
				REP(i, n) {
					if (i!=bestB.first && ((distR[i]-distA[i]) > bestA.second)) {
						bestA = mp(i, (distR[i]-distA[i]));
					}
				}
			}
		}

		if (bestA.first>=0)
			result += distA[bestA.first];
		if (bestB.first>=0)
			result += distB[bestB.first];

		REP(i, n) {
			if (i!=bestB.first && i!=bestA.first)
				result += distR[i];
		}

	}

	printf("%.8lf\n", result);
	return 0;

}

//