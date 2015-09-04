/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/w17/challenges/find-the-robot

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

int a[100000];

int main() {

	ll int t, n;
	scanf("%lld", &t);
	REP(tc, t) {
		scanf("%lld", &n);
		ll int r = ceil((float)n--/4);
		ll int u = ceil((float)n--/4);
		ll int l = ceil((float)n--/4);
		ll int d = ceil((float)n--/4);
		ll int x = (r*(r-1)*2 + 1*r) - (l*(l-1)*2 + 3*l);
		ll int y = (u*(u-1)*2 + 2*u) - (d*(d-1)*2 + 4*d);
		printf("%lld %lld\n", x, y);
	}
	return 0;
}

//Pre Tests Passed :)