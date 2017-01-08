#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include<assert.h>
#include <algorithm>
#include <iostream>
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



int isPrimeFib(ll int x){
	if (x<2)
		return 0;
	else if (x == 2 || x == 4)
		return 1;
	int lim = sqrt(x);
	FOR(i, 2, lim)
	if (x%i == 0)
		return 0;
	return 1;
}

int main(){

	ll int t, n, c;
	scanf("%lld", &t);
	REP(tc, t){
		c = 0;
		scanf("%lld", &n);
		int lim = sqrt(n);
		FOR(i, 1, lim){
			if (n%i == 0){
				c++;
				if (n / i>lim)
					c++;
			}
		}
		if (c == 2)
			c++;
		printf("%lld\n", c);
	}
	sp;
	return 0;
}