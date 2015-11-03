/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/TRT/

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

int a[2000];
bool calc[2000][2000];
ll int DP[2000][2000];

ll int sale(int l, int r, int day) {

	if (calc[l][r])
		return DP[l][r];

	if (l==r) 
		DP[l][r] = a[l]*day;
	else
		DP[l][r] = max(a[l]*day + sale(l+1, r, day+1), a[r]*day + sale(l, r-1, day+1));

	calc[l][r] = 1;
	return DP[l][r];

}

int main(){

	int n;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", &a[i]);

	ll int profit = sale(0, n-1, 1);
	printf("%lld\n", profit);
	sp;
	return 0;
}

//Solved