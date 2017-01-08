
//http://www.hackerearth.com/cryptex/algorithm/jamun-is-confused/

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

void scanint(int &x){
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}


int gcd(int a, int b) {
	int r;
	while (b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(){

	int a[1000];
	int t, n, ans, pos, least;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n)
			scanint(a[i]);
		ans = a[0];
		for (int i = 1; i <n; i++){
			ans = gcd(ans, a[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

//Solved