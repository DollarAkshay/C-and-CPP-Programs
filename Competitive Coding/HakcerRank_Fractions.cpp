/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/hourrank-2/challenges/fractions

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

int n;
int a[100000];

int getS(int x) {

	int s = 0;
	REP(i, n) {
		int b = a[i]/x;
		if (b==0 || a[i]/b!=x)
			return -1;
		while (b-1>=1 && a[i]/(b-1) == x)
			b--;
		s += b;
	}
	return s;
}

int main(){

	int ans = 0;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &a[i]);
		ans += a[i];
	}
	FOR(i, 2, 2000) {
		int s = getS(i);
		if (s!=-1)
			ans = min(ans, s);
	}
	printf("%d", ans);

	return 0;
}

//Solved