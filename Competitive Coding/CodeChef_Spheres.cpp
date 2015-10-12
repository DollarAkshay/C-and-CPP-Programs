/*~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/OCT15/problems/KSPHERES

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

int u[1010], l[1010];
vector<ll int> ways;
ll int DP[1010][1010];
ll int ans[1010];

void TopDownDP(int n) {

	FOR(i, 1, n) {
		FORD(j, ways.size()-1-i, 0)
			DP[i][j] = (DP[i][j+1] + DP[i-1][j+1]*ways[j])%MOD;
	}
}

void DEB(int n) {
	printf("Ways : \n");
	REP(i, ways.size())
		printf("%4d ", ways[i]);
	printf("\nDP : \n");
	FOR(i, 0, n) {
		REP(j, ways.size()) {
			printf("%4d ", DP[i][j]);
		}
		printf("\n");
	}

}

int main() {

	int n, m, c, r;
	scanf("%d%d%d", &n, &m, &c);
	REP(i, n) {
		scanf("%d", &r);
		u[r]++;
	}
	REP(i, m) {
		scanf("%d", &r);
		l[r]++;
	}
	REP(i, 1001) {
		if (u[i] && l[i]) {
			ways.pb(((ll int)u[i]*l[i])%MOD);
		}
	}
	FORD(i, ways.size()-1, 0) {
		DP[0][i] = (DP[0][i+1]+ways[i])%MOD;
	}
	TopDownDP(c);

	FOR(i, 1, c) {
		printf("%lld ", DP[i][0]);
	}
	printf("\n");
	sp;
	return 0;
}

//Solved