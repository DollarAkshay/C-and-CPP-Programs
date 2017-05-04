/*~~~~~~~~~~~~~~~~~~*
*                  *
* Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/codeagon/challenges/elemental-orbs

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
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS(x,n) memset(x,n,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int blast[2000];

ll int res = 0;
int n, e;


void dfs(int size, int prevType, int seq) {

	if (size == n) {
		res++;
	}
	else {
		REP(curType, e) {
			if (prevType == curType) {
				if (seq < blast[curType]) {
					dfs(size + 1, curType, seq+1);
				}
			}
			else {
				dfs(size+1, curType, 1);
			}
		}
	}


}


int main() {

	int t;
	scanf("%d", &t);
	REP(tc, t) {
		scanf("%d %d", &n, &e);
		REP(i, e)
			scanf("%d", &blast[i]);

		res = 0;

		dfs(0, -1, 0);

		printf("%lld\n", res%MOD);

	}

	return 0;
}

// TLE