/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/navi-and-maths/

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

ll int p;
vector<int> choosen;

ll int invert_mod(ll int a, ll int p) {
	ll int ne = 1, old = 0, q = p, r, h;
	int pos = 0;
	while (a > 0) {
		r = q%a;
		q = q / a;
		h = q*ne + old;
		old = ne;
		ne = h;
		q = a;
		a = r;
		pos = !pos;
	}
	return pos?old:(p - old);
}

ll int findP() {

	ll int res = 1, sum = 0;
	REP(i, choosen.size()) {
		res = (res*choosen[i])%MOD;
		sum += choosen[i];
	}
	return (res * invert_mod(sum, MOD))%MOD;
}

void maximizeP(int k, int n) {

	if (k==n) {
		p = max(p, findP());
	}
	else {
		choosen.push_back(a[k]);
		maximizeP(k+1, n);
		choosen.pop_back();
		maximizeP(k+1, n);
	}

}


int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n)
			scanf("%d", &a[i]);
		p = 0;
		maximizeP(0, n);
		printf("Case #%d: %lld\n", tc+1, p);
	}
	sp;
	return 0;
}

//Solved