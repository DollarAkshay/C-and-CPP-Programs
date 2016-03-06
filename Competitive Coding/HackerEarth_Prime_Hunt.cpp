/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/megacodants/algorithm/prime-hunt/

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

bool p[100000001];

void seive() {

	MS1(p);
	p[0] = p[1] = 0;

	int lim = sqrt(100000000);

	for (int i = 2; i<=lim; i++) {
		if (p[i]) {
			for (ll int j = i*i; j<100000001; j += i)
				p[j] = 0;
		}
	}



}

int main() {

	seive();
	int t, n, m;
	scanf("%d", &t);
	REP(tc, t) {
		scanf("%d %d", &n, &m);
		int res = 0;
		FOR(i, n, m) {
			if (p[i])
				res++;
		}
		printf("%d\n", res);
	}
	sp;
	return 0;
}

//Solved