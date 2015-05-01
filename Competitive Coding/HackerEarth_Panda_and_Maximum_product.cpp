/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/may-easy-challenge-15/algorithm/panda-and-maximum-product/

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

	int t, x, a = -1000000000, b = -1000000000, c = 1000000000, d = 1000000000;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &x);
		if (x > a){
			b = a;
			a = x;
		}
		else if (x > b)
			b = x;

		if (x < c){
			d = c;
			c = x;
		}
		else if (x < d)
			d = x;
	}
	ll int ans = max((ll int)a*b, (ll int)c*d);
	printf("%lld\n", ans);
	return 0;
}

//Solved