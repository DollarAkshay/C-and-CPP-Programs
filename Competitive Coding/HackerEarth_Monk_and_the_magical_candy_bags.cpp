/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-monk-c-stl/algorithm/monk-and-the-magical-candy-bags/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int main(){

	int t, n, m;
	int a[100000];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &m);
		REP(i, n)
			scanf("%d", &a[i]);
		ll int ans = 0;
		REP(i, m){
			SORT(a, n);
			ans += a[n - 1];
			a[n - 1] /= 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

//Partially Solved ~ TLE