/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/hourrank-1/challenges/shafaet-and-array

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

int a[10000];

int cost(int n, int k, int l) {

	int maxVal = a[n-1], res = 0;
	REP(i, n) {
		res += (maxVal-a[i])*l;
	}
	return res;
}

int main() {

	int n, k, l;
	scanf("%d%d%d", &n, &k, &l);
	REP(i, n)
		scanf("%d", &a[i]);
	int ans = 1000000000, swap = 0;
	while (true) {
		SORT(a, n);
		ans = min(ans, swap*k + cost(n, k, l));
		if (a[n-1]-a[0]<=1)
			break;
		else {
			a[n-1]--;
			a[0]++;
			swap++;
		}
	}
	printf("%d", ans);
	sp;
	return 0;
}

//Solved