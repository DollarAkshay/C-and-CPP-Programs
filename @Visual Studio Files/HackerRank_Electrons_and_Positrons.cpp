/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * Dollar Akshay$   *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/codeagon/challenges/back-to-origin

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
#define MS(x,n) memset(x,n,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

struct point {
	int x, y;
	point() {
		x = 0;
		y = 0;
	}

	point(int px, int py) {
		x = px;
		y = py;
	}

};

int x, y, res;
int taken[2000];
int epcolision[2000][2000];

point ele[2000], pos[2000];

int willcollide(int e, int p) {

	ll int dx = abs((ll int)ele[e].x - pos[p].x);
	ll int dy = abs((ll int)ele[e].y - pos[p].y);

	if (dx == 0 || dy == 0 || dx == dy)
		return 1;
	else
		return 0;

}


void backTrack(int e, int colided) {

	if (colided + (x - e) <= res) {
		return;
	}

	if (e == x) {
		res = max(res, colided);
	}

	else {
		
		REP(i, y) {
			if (epcolision[e][i]==1 && taken[i] == 0) {
				taken[i] = 1;
				backTrack(e + 1, colided + 1);
				taken[i] = 0;
			}
		}

		backTrack(e + 1, colided);
	}
}

int main() {

	int t;
	scanf("%d", &t);
	REP(tc, t) {
		scanf("%d %d", &x, &y);

		int xc = 0, yc = 0;
		int xcold[2000], ycold[2000];
		MS(xcold, 0);
		MS(ycold, 0);

		REP(i, x) 
			scanf("%d %d", &ele[i].x, &ele[i].y);
		REP(i, y) 
			scanf("%d %d", &pos[i].x, &pos[i].y);
		REP(i, x) {
			REP(j, y) {
				epcolision[i][j] = willcollide(i, j);
				if (epcolision[i][j] == 1) {
					if (xcold[i] != 1) {
						xc++;
						xcold[i] = 1;
					}
					if (ycold[j] != 1) {
						yc++;
						ycold[j] = 1;
					}
				}

			}
		}

		
		
		
		printf("%d\n", min(xc, yc));

	}
	
	return 0;
}

//