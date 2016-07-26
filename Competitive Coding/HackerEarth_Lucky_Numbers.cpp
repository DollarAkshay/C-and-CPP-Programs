/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/lucky-numbers-20/

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

ll int p2[100];

void generatePowersof2() {

	p2[0] = 1;

	int k = 0;
	while (p2[k] <= 1E18) {
		p2[k+1] = 2*p2[k];
		k++;
	}

}

int main() {

	generatePowersof2();

	ll int t, n;
	scanf("%lld", &t);
	REP(tc, t) {

		ll int res = 0;
		scanf("%lld", &n);

		for (int i = 0; p2[i]<=n; i++) {
			for (int j = i+1; p2[i]+p2[j] <= n; j++) {
				res = (res + p2[i] + p2[j])%MOD;
			}
		}
		printf("%lld\n", res);

	}
	sp;
	return 0;
}

//Solved