/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/1507622b5ca3d9dbf67ee27b081ddabce4025e8

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

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(s,x) fprintf(stderr,s,x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
struct point{
	int x, y;
};

int main(){

	ll int x, ans = 0, ysum = 0, xmin = 10000000000, xmax = -10000000000;
	int n,y[100005];
	scanf("%d", &n);
	REP(i, n){
		scanf("%lld %d", &x, &y[i]);
		xmin = min(x, xmin);
		xmax = max(xmax, x);
	}
	ans += xmax - xmin;
	SORT(y, n);
	if (n % 2){
		REP(i, n)
			ans += abs(y[i] - y[n/2]);
	}
	else{
		ll int p1 = 0, p2 = 0;
		REP(i, n)
			p1 += abs(y[i] - y[n/2]);
		REP(i, n)
			p2 += abs(y[i] - y[n/2+1]);
		ans += min(p1, p2);
	}
	printf("%lld\n",ans);
	return 0;
}

//Solved