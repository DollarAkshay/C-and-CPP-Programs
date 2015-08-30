/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-monk-bit-manipulation/algorithm/monk-in-the-magical-land/

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

int t, n, m, k;
int key[1000];
vector<pii> chest;

int gcd(int a, int b) {
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

int subsetSolve(int x) {

	int v[1000];
	MS0(v);
	bitset<32> bits(x);
	int res = 0;
	REP(i, n) {
		if (bits.test(i)) {
			REP(j, m) {
				if (v[j]==0 && gcd(key[i], chest[j].first)>1) {
					v[j] = 1;
					res += chest[j].second;
				}
			}
		}
	}
	return res;
}


int main() {


	scanf("%d", &t);
	REP(tc, t) {
		chest.clear();
		scanf("%d%d%d", &n, &m, &k);
		REP(i, n)
			scanf("%d", &key[i]);
		REP(i, m) {
			int x;
			scanf("%d", &x);
			chest.pb(mp(x, 0));
		}
		REP(i, m)
			scanf("%d", &chest[i].second);

		int lim = 1<<n, ans = 0;
		REP(i, lim) {
			bitset<32> bits(i);
			if (bits.count()==k) {
				int ss = subsetSolve(i);
				if (ss>ans) {
					ans = ss;
				}
			}
		}
		printf("%d\n", ans);

	}
	return 0;
}

//Partially Solved ~TLE