/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/557/problem/B

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

	int n, w;
	int a[200000];
	scanf("%d%d", &n, &w);
	REP(i, 2 * n)
		scanf("%d", &a[i]);

	SORT(a, 2*n);

	double g = (double)a[0], b = (double)a[n];
	double x = min(b/2, g);
	if ((double)w >= 3*x*n){
		double ans = x * 3 * n;
		printf("%lf\n", ans);
	}
	else{
		x = w/(3*(double)n);
		double ans = x * 3 * n;
		printf("%lf\n", ans);
	}
	return 0;
}

//Pre-Test Passed