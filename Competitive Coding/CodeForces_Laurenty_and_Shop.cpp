/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/586/problem/B

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

int cum[2][50];
int b[50];
int path[50];

int main(){

	int n;
	scanf("%d", &n);
	REP(i, n-1) {
		int x;
		scanf("%d", &x);
		cum[0][i+1] = i==0?x:cum[0][i]+x;
	}
	REP(i, n-1) {
		int x;
		scanf("%d", &x);
		cum[1][i+1] = i==0?x:cum[1][i]+x;
	}
	REP(i, n)
		scanf("%d", &b[i]);

	REP(i, n) {
		path[i] = cum[0][i] + b[i] + cum[1][n-1]-cum[1][i];
	}
	SORT(path, n);
	printf("%d\n", path[0]+path[1]);
	return 0;
}

//Pretest Passed