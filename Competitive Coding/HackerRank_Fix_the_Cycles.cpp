/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/w19/challenges/fix-the-cycles

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

int a[6];

bool hasNegativeCycles() {

	if(a[0]+a[1]+a[2]+a[3]<0)
		return true;
	if (a[0]+a[1]+a[5]<0)
		return true;
	if (a[0]+a[4]+a[3]<0)
		return true;

	return false;

}

int main() {

	
	REP(i, 6)
		scanf("%d", &a[i]);

	bool found = 0;
	int res = 10000;
	REP(i, 6) {
		FORD(j, 200, 0) {
			a[i] += j;
			if (hasNegativeCycles()==false) {
				found = 1;
				res = min(res, j);
			}
			a[i] -= j;
		}
	}
	if (found)
		printf("%d\n", res);
	else
		printf("-1\n");
	sp;
	return 0;
}

//Solved Pre-Test