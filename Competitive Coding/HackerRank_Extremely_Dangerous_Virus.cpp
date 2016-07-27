/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/rookierank/challenges/extremely-dangerous-virus

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

ll int fastpowMod(ll int b,ll int e) {

	if (e==1) {
		return b%MOD;
	}
	else if (e%2) {
		ll int res = fastpowMod(b, e/2);
		return (((res*res)%MOD)*b)%MOD;
	}
	else {
		ll int res = fastpowMod(b, e/2);
		return (res*res)%MOD;
	}

}

int main(){

	ll int a, b, t;
	scanf("%lld %lld %lld", &a, &b, &t);

	int base = (a+b)/2;

	printf("%lld", fastpowMod(base, t));

	return 0;
}

//Solved