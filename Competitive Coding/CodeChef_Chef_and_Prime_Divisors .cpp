/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/MAY15/problems/CHAPD

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

vector<ll int> p;

int isPrime(ll int x){

	int lim = sqrt(x);
	FOR(i, 2, lim){
		if (x%i == 0)
			return 0;
	}
	return 1;
}


int pdiv(ll int a, ll int b){

	if (a%b == 0)
		return 1;
	if (a == 1)
		return 0;

	int lim = sqrt(b);
	FOR(i, 2, lim){
		if (isPrime(i) && b%i == 0){
			if (a%i)
				return 0;
			else{
				while (b%i == 0) b /= i;
				while (a%i == 0) a /= i;
				return pdiv(a, b);
			}
		}
	}
	assert(1 == 0);
	return 0;

}

int main(){

	ll int t, a, b;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld", &a, &b);
		int ans = -1;
		if (a%b == 0)
			ans = 1;
		else
			ans = pdiv(a, b);
		puts(ans ? "Yes" : "No");
	}
	return 0;
}

// 