/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/rookierank/challenges/magic-square-forming

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

int magic[8][3][3] = { 
	{ { 8, 1, 6 },{ 3, 5, 7 },{ 4, 9, 2 } },
	{ { 6, 1, 8 },{ 7, 5, 3 },{ 2, 9, 4 } },
	{ { 4, 9, 2 },{ 3, 5, 7 },{ 8, 1, 6 } },
	{ { 2, 9, 4 },{ 7, 5, 3 },{ 6, 1, 8 } },
	{ { 8, 3, 4 },{ 1, 5, 9 },{ 6, 7, 2 } },
	{ { 4, 3, 8 },{ 9, 5, 1 },{ 2, 7, 6 } },
	{ { 6, 7, 2 },{ 1, 5, 9 },{ 8, 3, 4 } },
	{ { 2, 7, 6 },{ 9, 5, 1 },{ 4, 3, 8 } } 
};




int main(){

	int m[3][3];

	REP(i, 3) 
		REP(j, 3)
			scanf("%d", &m[i][j]);

	int res = 10000;
	REP(k, 8) {
		int cost = 0;
		REP(i, 3) {
			REP(j, 3) {
				cost += abs(m[i][j] - magic[k][i][j]);
			}
		}
		res = min(res, cost);
	}
	printf("%d", res);
	return 0;
}

//Solved