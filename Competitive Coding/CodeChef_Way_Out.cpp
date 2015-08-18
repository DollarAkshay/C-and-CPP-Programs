/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/AUG15/problems/WOUT

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


int main(){

	ll int t, n, h;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld", &n, &h);
		ll int empty[1000001];
		MS0(empty);
		REP(i, n){
			ll int u, b;
			scanf("%lld%lld", &b, &u);
			empty[b]++;
			empty[u+1]--;
		}
		REP(i, n+1)
			empty[i] = i?empty[i-1]+empty[i]:empty[i];
		ll int area = h*n;
		REP(i, h)
			area -= empty[i];
		ll int ans = n*h;
		REP(i, n-h+1){
			ans = min(ans, area);
			area += empty[i] - empty[i+h];
		}
		printf("%lld\n", ans);
	}
	sp;
	return 0;
}

//Solved