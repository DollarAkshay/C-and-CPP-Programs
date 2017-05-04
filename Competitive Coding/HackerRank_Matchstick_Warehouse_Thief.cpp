/*~~~~~~~~~~~~~~~~~~*
*                  *
* Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/codeagon/challenges/matchstick-warehouse-thief

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

vector<pii> crateinfo;

int main() {

	int n, c;
	scanf("%d %d", &n, &c);
	REP(i, c) {
		int box, matches;
		scanf("%d %d", &box, &matches);
		crateinfo.push_back(mp(matches, box));
	}

	SORT(crateinfo, crateinfo.size());
	REV(crateinfo, crateinfo.size());


	ll int sum = 0, curBoxes = 0;
	REP(i, crateinfo.size()) {

		if (curBoxes + crateinfo[i].second <= n) {
			curBoxes += crateinfo[i].second;
			sum += crateinfo[i].second*crateinfo[i].first;
		}
		else {
			int rem = n - curBoxes;
			curBoxes = n;
			sum += rem*crateinfo[i].first;
		}

		if (curBoxes == n) {
			break;
		}
	}
	printf("%lld", sum);
	return 0;
}

//Solved