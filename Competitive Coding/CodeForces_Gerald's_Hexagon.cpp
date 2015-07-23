/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/560/problem/C

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

int a[6];

int main(){

	REP(i, 6)
		scanf("%d", &a[i]);

	int s1=0, l1=0, s2=0, l2=0;
	REP(i, 6){
		int prev = (i-1)%6;
		int next = (i+1)%6;
		if (prev<0)
			prev += 6;
		if (a[prev]==a[next]){
			s1 = i;
			l1 = a[prev];
			break;
		}
	}

	REP(i, 6){
		int prev = (i-1)%6;
		int next = (i+1)%6;
		if (prev<0)
			prev += 6;
		if (a[prev]==a[next] && i!=s1){
			s2 = i;
			l2 = a[prev];
		}
	}



	ll int ans = 0, base = a[s1]+l1-1;
	REP(i, l1)
		ans += 2*(base-i) +1;
	REP(i, l2)
		ans += 2*(base-i) +1;
	printf("%I64d\n", ans);
	return 0;
}

//