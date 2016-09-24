/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/AUG16/problems/CHEFRRUN

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

ll int graph[100000];
ll int inDeg[100000];

int main(){

	ll int t, n, x;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);

		REP(i, n) {
			scanf("%lld", &x);
			ll int v = ( i+x+1 ) % n;
			assert(v>=0);
			graph[i] = v;
			inDeg[v]++;
		}

		ll int magic = n;
		queue<ll int> q;

		REP(i, n) {
			if (inDeg[i]==0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			ll int u = q.front();
			q.pop();
			ll int v = graph[u];
			magic--;
			assert(magic>0);
			if (--inDeg[v]==0) {
				q.push(v);
			}
		}

		MS0(inDeg);
		printf("%lld\n", magic);
	}
	return 0;
}

//