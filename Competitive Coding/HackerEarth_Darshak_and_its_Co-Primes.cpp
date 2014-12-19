/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.hackerearth.com/tcetcyphers-5/algorithm/darshak-and-its-co-primes/

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

ll int gcd(ll int a, ll int b){
	ll int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

int main(){

	int t, a, b;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%lld%lld", &a, &b);
		puts(gcd(a, b) == 1 ? "Is a Co-Prime" : "Not a Co-Prime");
	}
	return 0;
}

//Solved