/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/september-easy-15/algorithm/minimum-class/

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

int bsearch_gt(int n) {

	int lo = 0, hi = 1000000000;
	ll int res = -1;
	while (lo<=hi) {
		ll int mid = (lo+hi)/2;
		if (mid*(mid+1)>=n) {
			res = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}
	return res*(res+1)==n?res:res-1;
}


int main() {

	int t, n;
	scanf("%d", &t);
	REP(tc, t) {
		scanf("%d", &n);
		int i = 1, day = 0;
		while (n>0) {
			n -= i;
			day++;
			if (n<=0)
				break;
			n -= i;
			day++;
			if (n<=0)
				break;

			i++;
		}
		printf("%d\n", day);
	}
	return 0;
}

//Solved