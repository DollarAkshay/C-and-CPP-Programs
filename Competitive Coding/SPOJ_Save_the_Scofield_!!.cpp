/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/UJ01/

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

ll int gcd(ll int a, ll int b){

	ll int c;
	while (a != 0) {
		c = a; 
		a = b%a;  
		b = c;
	}
	return b;
}

int main(){

	int t;
	scanf("%d", &t);
	REP(tc, t){
		ll int a, b, n;
		scanf("%lld %lld %lld", &a, &b, &n);

		ll int lcm = a*b/gcd(a, b);

		ll int cycle = lcm/a + lcm/b -1;

		ll int res_a = lcm*(n/cycle), res_b = lcm*(n/cycle);

		REP(i, n%cycle) {
			if (res_a+a < res_b+b)
				res_a += a;
			else
				res_b += b;
		}

		printf("%lld\n", max(res_a, res_b));
	}
	sp;
	return 0;
}

//