/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/armada-2/algorithm/nikhil-and-his-friends/

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

ll int a[1000001];
ll int c[1000001];
int main() {

	ll int t, n, x;
	scanf("%lld", &t);
	REP(tc, t) {
		scanf("%lld%lld", &n, &x);
		REP(i, n) {
			scanf("%lld", &a[i]);
			c[i+1] = i?a[i] + c[i]:a[i];
		}
		int found = 0;
		REP(i, n) {
			FOR(j, i, n-1) {
				if (c[j]-c[i]==x) {
					found = 1;
					i = n;
					break;
				}
			}
		}
		puts(found?"Yes":"No");
	}
	sp;
	return 0;
}

//