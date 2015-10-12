/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/morgan-stanley-2015/challenges/stock-values

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

int a[20];

int val(int n) {

	int res = 0;
	REP(i, n/2)
		res += abs(a[i]-a[n-i-1]);
	return res;

}

int rec(int k, int n) {

	if (k==n-1)
		return val(n);
	else {
		int change = -1, nochange = -1;
		if (a[k-1]%2==0 && a[k+1]%2==0) {
			int t = a[k];
			a[k] = (a[k-1]+a[k+1])/2;
			change = rec(k+1, n);
			a[k] = t;
		}
		nochange = rec(k+1, n);
		return max(nochange, change);
	}
}

int main() {

	int t, n;
	scanf("%d", &t);
	REP(tc, t) {
		scanf("%d", &n);
		REP(i, n)
			scanf("%d", &a[i]);
		printf("%d\n", rec(1, n));
	}
	sp;
	return 0;
}

//Solved