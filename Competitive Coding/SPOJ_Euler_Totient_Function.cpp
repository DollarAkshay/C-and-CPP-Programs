/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/ETF/

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

bool p[1000010];

void siev() {

	MS1(p);
	p[0] = p[1] = 0;
	int lim = sqrt(1000000);
	for (int i = 2; i<lim; i++) {
		if (p[i]) {
			for (int j = i*i; j<=1000000; j += i)
				p[j] = 0;
		}
	}

}

int main(){

	siev();

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		ll int res = n;

		int lim = sqrt(n);

		FOR(i, 1, lim) {
			if (n%i==0) {
				if (p[i])
					res = res*(i-1)/i;
				if (p[n/i] && n/i>lim)
					res = res*(n/i-1)/(n/i);
			}
		}
		printf("%lld\n", res);

	}
	sp;
	return 0;
}

//Solved