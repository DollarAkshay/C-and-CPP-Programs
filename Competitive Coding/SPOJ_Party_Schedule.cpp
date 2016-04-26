/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/PARTY/

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

int DP[101][501];
vector<pii> party;

int main(){

	int cash, n;
	while (1) {

		scanf("%d %d", &cash, &n);
		if (cash==0 && n==0)
			break;

		REP(i, n) {
			int fee, fun;
			scanf("%d %d", &fee, &fun);
			party.push_back(mp(fee, fun));
		}

		REP(i, party.size()) {
			REP(j, cash+1) {
				if (party[i].first>j)
					DP[i+1][j] = DP[i][j];
				else
					DP[i+1][j] = max(DP[i][j], DP[i][j-party[i].first] + party[i].second);
			}
		}

		while (cash>0 && DP[n][cash]==DP[n][cash-1])
			cash--;

		printf("%d %d\n", cash, DP[n][cash]);
		MS0(DP[0]);
		party.clear();
	}
	sp;
	return 0;
}

//Solved