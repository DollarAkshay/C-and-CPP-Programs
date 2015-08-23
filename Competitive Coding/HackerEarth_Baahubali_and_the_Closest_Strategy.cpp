/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/cm1508/algorithm/baahubali-and-the-closest-strategy/

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

int a[100000];
vector<int> res;

pii bsearch_range(int key) {

	int lo = 0, hi = res.size()-1, mid;
	pii ans;

	while (lo<=hi) {
		if (res[lo]<=key && key<=res[hi]) {
			ans = mp(lo, hi);
		}
		mid = (lo+hi)/2;
		if (key>res[mid]) {
			lo = mid+1;
		}
		else {
			hi = mid-1;
		}
	}
	return ans;
}

int main(){

	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, n)
		scanf("%d", &a[i]);
	REP(i, n) {
		FOR(j,i+1,n-1)
			res.pb(a[i]+a[j]);
	}
	SORT(res,res.size());
	REP(i, m) {
		int x;
		scanf("%d", &x);
		int diff = 2000000000, ans=-1;
		REP(j,res.size()) {
			if (abs(res[j]-x)<diff) {
				diff = abs(res[j]-x);
				ans = res[j];
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

//