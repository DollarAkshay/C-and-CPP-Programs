


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

int terminating(int x){

	while (x % 2 == 0)
		x /= 2;
	while (x % 5 == 0)
		x /= 5;
	if (x == 1)
		return 1;
	return 0;
}

int gcd(int a, int b){
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}


int main(){
	int t;
	ll int x1, x2, y1, y2;
	ll int ans;
	scanf("%d", &t);
	REP(tc, t){
		int spec = 0;
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		if (x1 == x2 || y1 == y2){
			ans = abs(y1 - y2) + abs(x1 - x2) - 1;
			if (ans == -1)
				ans = 0;
			printf("%lld\n", ans);
		}
		else{
			ll int den = abs(x1 - x2), num = abs(y1 - y2);
			ans = gcd(den, num) - 1;
			printf("%lld\n", ans);
		}
	}
	return 0;
}

//Solved