/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-monk-bit-manipulation/algorithm/monks-choice-of-numbers-1/

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

	int t, n, k;
	scanf("%d", &t);
	REP(tc, t) {
		scanf("%d%d", &n, &k);
		vector<pii> a;
		REP(i, n) {
			int x;
			scanf("%d", &x);
			bitset<32> bits(x);
			a.pb(mp(bits.count(), x));
		}
		SORT(a, n);
		REV(a, n);
		int ans = 0;
		REP(i, k)
			ans += a[i].first;
		printf("%d\n", ans);
	}
	return 0;
}

//Solved