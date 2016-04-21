/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/projecteuler/challenges/euler011

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

point dir[9] = {{-1,-1}, { 0,-1}, { 1,-1},
				{-1, 0}, { 0, 0}, { 1, 0}, 
				{-1, 1}, { 0, 1}, { 1, 1} };

int a[100][100];

ll int findMax(int i, int j) {

	ll int resmax = -1;

	REP(d, 9) {
		if (d==4)
			continue;
		ll int prod = 1;
		REP(k, 4) {
			int dx = j + k*dir[d].x, dy = i + k*dir[d].y;
			if (dx>=0 && dx<20 && dy>=0 && dy<20)
				prod *= a[dy][dx];
			else
				prod = 0;
		}

		resmax = max(resmax, prod);
	}

	return resmax;

}

int main(){

	REP(i, 20) {
		REP(j, 20)
			scanf("%d", &a[i][j]);
	}

	ll int res = -1;
	REP(i, 20) {
		REP(j, 20)
			res = max(res, findMax(i, j));
	}

	printf("%lld\n", res);
	sp;
	return 0;
}

//Solved