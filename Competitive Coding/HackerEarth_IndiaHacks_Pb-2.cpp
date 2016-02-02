/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/indiahacks-code-mania-9/algorithm/indiahacks-pb-3/

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

int n, k;

int a[10000];

bool calc[10002];
ll int DP[10002];



ll int solve(int pos) {

	if (pos>=n)
		return 0;
	if (calc[pos])
		return DP[pos];

	DP[pos] = 0;
	DP[pos] = max(DP[pos], solve(pos+1));
	DP[pos] = max(DP[pos], a[pos] + solve(pos+1+k));

	calc[pos] = true;

	return DP[pos];

}

int main(){

	int t;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &k);
		ll int sum = 0;
		REP(i, n) {
			scanf("%d", &a[i]);
			sum += a[i]>0?a[i]:0;
		}
		ll int ans = k?solve(0):sum;
		printf("%lld\n", ans);
		MS0(calc);
	}
	return 0;
}

//Solved