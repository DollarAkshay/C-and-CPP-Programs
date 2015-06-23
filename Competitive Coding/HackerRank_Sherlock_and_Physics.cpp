/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/101hack26/challenges/sherlock-and-physics

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

ll int gcd(ll int a, ll int b){
	ll int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

void printfraction(double x, ll int b){

	while ((int)rint(fmod(x, 100)) != 0){
		x *= 10;
		b *= 10;
	}
	x /= 100;
	b /= 100;
	ll int a = (int)rint(x);
	ll int fac = gcd(a, b);
	while (fac > 1){
		a /= fac;
		b /= fac;
		fac = gcd(a, b);
	}
	if (a == 0)
		b == 1;
	printf("%lld/%lld",a,b);

}

int main(){

	int t, r, s;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &r, &s);
		double deg;
		while (1){
			deg = fmod(360 * r / (double)s, 360);
			if (deg >= 0 && deg <= 90)
				break;
			r++;
		}

		printf("%d ", r);
		printfraction(deg, 360);
		printf("\n");
	}
	return 0;
}

//