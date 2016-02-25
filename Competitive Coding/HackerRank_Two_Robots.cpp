/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/w19/challenges/two-robots

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


int r1, r2;
vector<pii> q;

map<pii, bool> calc[1005];
map<pii, int> DP[1005];

int minD(int k, int r) {

	if (r==1) {
		if (r1==-1)
			return abs(q[k].first-q[k].second);
		else
			return abs(r1 - q[k].first) + abs(q[k].first - q[k].second);
	}
	else {
		if (r2==-1)
			return abs(q[k].first-q[k].second);
		else
			return abs(r2 - q[k].first) + abs(q[k].first - q[k].second);
	}

}

int rec_brute(int n, int k) {

	pii rpos = make_pair(r1, r2);

	if (calc[k][rpos])
		return DP[k][rpos];

	if (k>=n) {
		return 0;
	}
	else {
		int r1d = minD(k, 1);
		int r2d = minD(k, 2);

		int r1old = r1, r2old = r2;

		r1 = q[k].second;
		int r1min = r1d + rec_brute(n, k+1);
		r1 = r1old;

		r2 = q[k].second;
		int r2min = r2d + rec_brute(n, k+1);
		r2 = r2old;

		calc[k][rpos] = true;
		DP[k][rpos] = min(r1min, r2min);
		return min(r1min, r2min);
	}

}

int main() {

	int t, m, n;
	scanf("%d", &t);
	REP(tc, t) {
		scanf("%d %d", &m, &n);
		REP(i, n) {
			int ma, mb;
			scanf("%d %d", &ma, &mb);
			q.push_back(make_pair(ma, mb));
		}
		r1 = r2 = -1;
		int res = rec_brute(n, 0);
		printf("%d\n", res);

		REP(i, n+1) {
			calc[i].clear();
			DP[i].clear();
		}
		q.clear();

	}
	sp;
	return 0;
}

//Solved Preliminary Testcases