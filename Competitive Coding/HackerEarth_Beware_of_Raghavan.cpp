/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/epiphany-5/algorithm/beware-of-raghavan/

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

int a[10000000], n;
ll int DP[10000000];

ll int maxval(int l){

	if (l>=n)
		return 0;
	if (DP[l]!=-1)
		return DP[l];

	int with = a[l]+maxval(l+2);
	int wo = maxval(l+1);
	DP[l] = max(with, wo);

	return DP[l];
}

int main(){

	FILE *f = fopen("testcase.txt", "r");
	fscanf(f,"%d", &n);
	REP(i, n)
		fscanf(f,"%d", &a[i]);
	REP(i, n)
		DP[i] = -1;
	maxval(0);
	printf("%lld\n", DP[0]);
	sp;
	return 0;
}

//