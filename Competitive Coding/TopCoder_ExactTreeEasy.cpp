/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://arena.topcoder.com/#/u/coding/16511/13881/2

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


class ExactTreeEasy{

public:
	vector<int> getTree(int n, int m){
		vector<int> e;
		FOR(i, 0, n - m - 1){
			e.pb(i);
			e.pb(i+1);
		}
		FOR(i, n-m+1, n-1){
			e.pb(i);
			e.pb(n-m);
		}
		return e;
	}
};

int main() {
	ExactTreeEasy test;
	vector<int> a = test.getTree(3,2);
	REP(i, a.size())
		cout << a[i] << " ";
	sp;
	return 0;
}
//Solved