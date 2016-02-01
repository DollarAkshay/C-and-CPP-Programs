/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/hourrank-5/challenges/xor-se

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

int a[100000];

ll int XOR2(ll int n) {

	ll int res = 0;
	FORD(i, 60, 1) {
		ll int y = n%(1LL<<(i+1));
		if (y >= (1LL<<i))
			res += (y+1)%2;
		res = res<<1;
	}

	if (n%4==1 || n%4==2)
		res += 1;

	return res;
}

ll int XOR(ll int l, ll int r) {

	ll int res = r;
	ll int start = (r-l+1)%2==0?r-2:r-1;
	for (ll int i = start; i>=1; i -= 2)
		res ^= i;
	return XOR2(l-1)^res;

}

int main() {

	ll int t, l, r;
	scanf("%lld", &t);
	REP(tc, t) {
		scanf("%lld %lld", &l, &r);
		printf("%lld\n", XOR(l, r));
	}
	return 0;
}

//Not SOlved