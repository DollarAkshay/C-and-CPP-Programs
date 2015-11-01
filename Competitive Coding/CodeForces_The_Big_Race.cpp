/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/592/problem/C

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

ll int gcd(ll int a,ll int b) {
	ll int c;
	while (a != 0) {
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

int main(){

	ll int t, b, w, res, f;
	scanf("%I64d %I64d %I64d", &t, &w, &b);
	f = gcd(b, w);
	double full = (double)w/f*b;
	
	ll int lcm = w/f*b;

	if (full<(double)5000000000000000000) {
		res = t/lcm*min(b, w)+min(b, w)-1;
		if (t%lcm<min(b, w))
			res -= (min(b, w) - t%lcm - 1);
	}
	else {
		res =  min(b, w)-1;
		if (t<min(b, w))
			res -= (min(b, w) - t - 1);
	}
	f = gcd(res, t);
	printf("%I64d/%I64d\n", res/f, t/f);
	return 0;
}

//Solved ~ After the Contest