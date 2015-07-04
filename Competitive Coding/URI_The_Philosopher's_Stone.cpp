/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.urionlinejudge.com.br/judge/en/challenges/view/51/2

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
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

vector<pair<int, int>> x;

int main(){

	int t;
	scanf("%d", &t);
	REP(tc, t){
		int a, b;
		scanf("%d %d", &a, &b);
		assert(a >= 1 && a <= 3600);
		assert(b >= 1 && b <= 3600);
		assert(b >= a);
		x.pb(mp(b, a));
	}
	SORT(x, t);
	int ans = 0, last = 0;
	REP(i, x.size()){
		if (x[i].second >= last){
			ans += x[i].first - x[i].second;
			last = x[i].first;
		}
	}
	printf("%d\n", ans);
	return 0;
}

//Not Solved (70%)