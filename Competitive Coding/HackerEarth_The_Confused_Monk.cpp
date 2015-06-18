/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-monk-number-theory-i/algorithm/the-confused-monk/

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

int gcd(int a, int b){
	int c;
	while (a != 0) {
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}


int main(){

	int a[50], n, g;
	ll int f = 1, ans = 1;
	scanf("%d", &n);
	REP(i, n){
		scanf("%d", &a[i]);
		f = (f*a[i]) % MOD;
		if (g != 1)
			g = gcd(g, a[i]);
	}

	while (g){
		ans = (ans*f) % MOD;
		g--;
	}

	printf("%lld", ans);
	return 0;
}

//Solved