/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/roy-and-coin-boxes-1/

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
#define mp(x) make_pair(x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int box[1000001];
int s[1000000], e[1000000];
ll int cum[1000001];

int main(){

	int n, m, q;
	scanf("%d%d", &n, &m);
	REP(i, m){
		int l, r;
		scanf("%d%d", &l, &r);
		s[l - 1]++;
		e[r - 1]++;
	}

	ll int sum = s[0];
	box[sum]++;
	FOR(i, 1, n-1){
		sum = sum - e[i - 1] + s[i];
		box[sum]++;
	}
	FORD(i, n, 0)
		cum[i] = i == n ? box[i] : cum[i + 1] + box[i];

	scanf("%d", &q);
	REP(i, q){
		int x;
		scanf("%d", &x);
		printf("%lld\n", cum[x]);
	}

	return 0;
}

//Solved