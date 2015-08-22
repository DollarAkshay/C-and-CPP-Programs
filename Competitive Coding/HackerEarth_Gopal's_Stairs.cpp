/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codification/algorithm/gopals-stairs/

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

int a[100000];
ll int DP[100001];

ll int step(int n){

	if (n<0)
		return 0;
	else if (DP[n])
		return DP[n];
	else{
		DP[n] = (step(n-1) + step(n-2) + step(n-3))%MOD;
		return DP[n];
	}
}

int main(){

	DP[0] = DP[1] = 1;
	step(100000);
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		printf("%lld\n", DP[n]);
	}
	return 0;
}

//Solved