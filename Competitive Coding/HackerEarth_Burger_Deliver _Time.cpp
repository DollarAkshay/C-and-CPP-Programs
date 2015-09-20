/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-mania-100/algorithm/burger-deliver-time-1/

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

vector<int> a[1001];

class Compare {
public:
	bool operator() (pii lhs, pii rhs) {
		return (lhs.first>rhs.first) || (lhs.first==rhs.first && lhs.second>rhs.second);
	}
};

int main() {

	int n;
	priority_queue<pii, vector<pii>, Compare> q;
	scanf("%d", &n);
	REP(i, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		q.push(mp(x+y, i+1));
	}

	while (!q.empty()) {
		printf("%d ", q.top().second);
		q.pop();
	}

	return 0;
}

//Solved