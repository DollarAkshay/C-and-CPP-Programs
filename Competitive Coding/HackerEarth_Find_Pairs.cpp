/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code_hunt_11/algorithm/find-pairs/

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

int a[200000];

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		map<int, int> m;
		REP(i, n){
			int x;
			scanf("%d", &x);
			if (m.count(x))
				m[x]++;
			else
				m[x] = 1;
		}
		ll int ans = 0;
		map<int, int>::iterator it;
		for (it = m.begin(); it!=m.end(); it++){
			ll int c = it->second;
			ans += c*(c+1)/2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

//Solved