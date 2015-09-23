/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//

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

ll int rev(ll int n) {
	ll int res = 0;
	while (n) {
		res = res*10+n%10;
		n /= 10;
	}
	return res;
}

ll int minmov(ll int n) {

	if (n<=10)
		return n;


	if (n%10 && rev(n)<n)
		return 1 + min(minmov(rev(n)), minmov(n-1));
	else
		return 1 + minmov(n-1);

}

int main() {

	ll int t, n;
	scanf("%lld", &t);
	REP(tc, t) {
		scanf("%lld", &n);
		ll int steps = 0;
		printf("BF = %lld\n", minmov(n));
		while (n) {
			//printf("%lld,", n);
			ll int revn = rev(n);
			ll int revn1 = rev(n-1);
			if (n%10==1 && revn<n)
				n = revn;
			else
				n--;
			steps++;
		}
		printf("%lld\n", steps);
	}
	return 0;
}

//