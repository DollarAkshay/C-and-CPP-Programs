/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/projecteuler/challenges/euler010

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

vector<ll int> primes;
vector<ll int> sum_primes;

bool p[2000006];

void sieve() {

	MS1(p);
	p[0] = p[1] = 0;
	ll int lim = sqrt(2000006);

	for (ll int i = 2; i<=lim; i++) {
		if (p[i]) {
			for (ll int j = i*i; j<2000006; j += i)
				p[j] = 0;
		}
	}

	REP(i, 2000006) {
		if (p[i]) {
			primes.push_back(i);
			ll int last = sum_primes.size()?sum_primes.back():0;
			sum_primes.push_back(last + i);
		}
	}

	primes.push_back(2000005);
	sum_primes.push_back(sum_primes.back());

}

int main() {

	sieve();
	int t, n;
	scanf("%d", &t);
	REP(tc, t) {
		scanf("%d", &n);
		int pos = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
		printf("%lld\n", sum_primes[pos]-primes[pos]);
	}
	sp;
	return 0;
}

//Solved