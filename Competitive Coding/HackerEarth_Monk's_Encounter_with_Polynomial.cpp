/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-monk-searching/algorithm/monks-encounter-with-polynomial/

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
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
#define gc getchar_unlocked
struct Edge{ int v, w; };

int main(){

	ll int t, a, b, c, k;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
		c -= k;
		double r1 = (-b + sqrt((double)b*b - 4*a*c)) / (2 * a);
		double r2 = (-b - sqrt((double)b*b - 4*a*c)) / (2 * a);
		r1 = round(r1 * 10) / 10;
		r2 = round(r1 * 10) / 10;
		ll int ans1 = (ll int)ceil(r1), ans2 = (ll int)ceil(r2);
		if (ans1 < 0){
			printf("%lld\n", ans2);
		}
		else if (ans2 < 0){
			printf("%lld\n", ans1);
		}
		else{
			if (ans1<ans2)
				printf("%lld\n", ans1);
			else
				printf("%lld\n", ans2);
		}
	}
	return 0;
}

//