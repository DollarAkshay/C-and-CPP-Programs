/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/593/problem/B

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

ll int lx[100000];
ll int rx[100000];

vector<pair<ll int, ll int>> leftx;
vector<pair<ll int, ll int>> rightx;

bool comp1(pair<ll int, ll int> lhs, pair<ll int, ll int> rhs) {

	return (lhs.second<rhs.second)||(lhs.second==rhs.second && rx[lhs.first]<rx[rhs.first]);

}

bool comp2(pair<ll int, ll int> lhs, pair<ll int, ll int> rhs) {

	return (lhs.second<rhs.second)||(lhs.second==rhs.second && lx[lhs.first]<lx[rhs.first]);

}

int main(){

	ll int n, xl, xr;
	scanf("%I64d%I64d%I64d", &n, &xl, &xr);
	REP(i, n) {
		ll int m, c;
		scanf("%I64d%I64d", &m, &c);
		lx[i] = xl*m + c;
		rx[i] = xr*m + c;
		leftx.push_back(mp(i, lx[i]));
		rightx.push_back(mp(i, rx[i]));
	}

	sort(leftx.begin() , leftx.end() , comp1);
	sort(rightx.begin(), rightx.end(), comp2);

	int f = 0;
	REP(i, n) {
		if (leftx[i].first!=rightx[i].first) {
			f = 1;
			break;
		}
	}
	puts(f?"Yes":"No");
	return 0;
}

//Solved