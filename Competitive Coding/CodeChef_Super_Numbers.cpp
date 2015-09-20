/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/COOK62/problems/SPRNMBRS

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

set<ll int> s;
vector<ll int> a;

void gen(ll int n) {

	if (s.count(n)==0 && n<=1000000000000000000LL) {
		s.insert(n);
		a.pb(n);
		gen(n*2);
		gen(n*3);
	}

}

void pre() {

	a.pb(1);
	s.insert(1);
	gen(2);
	SORT(a, a.size());

}

int main(){

	pre();
	ll int t, l, r;
	scanf("%lld", &t);
	REP(tc, t) {
		scanf("%lld %lld", &l, &r);
		auto lo = lower_bound(a.begin(), a.end(), l), hi = upper_bound(a.begin(), a.end(), r);
		printf("%d\n", hi-lo);
	}
	sp;
	return 0;
}

//OMFGDFKLDJFIOEHFI I SOLVED THIS FUCK !!!