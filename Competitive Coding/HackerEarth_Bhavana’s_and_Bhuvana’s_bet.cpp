/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codification/algorithm/bhavanas-and-bhuvanas-bet/

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

int lim = 6074001000;

unsigned ll int gt_bsearch(unsigned ll int l, unsigned ll int h, unsigned ll int key){

	unsigned ll int res = -1;
	while (l<=h){
		unsigned ll int mid = (l+h)/2;
		unsigned ll int sum = mid*(mid+1)/2;
		if (sum>=key){
			res = mid;
			h = mid-1;
		}
		else
			l = mid+1;
	}
	return res;
}

int main(){

	unsigned ll int t, n;
	scanf("%llu", &t);
	REP(tc, t){
		scanf("%llu", &n);
		unsigned ll int ans, mad = pow(2,63);
		assert(n<=mad);
		ans = gt_bsearch(1, lim-1, n);
		printf("%llu\n", ans-1);
	}
	sp;
	return 0;
}

//