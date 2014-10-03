#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
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

void scanint(ll int &x){
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

int main(){

	ll int f[10];
	ll int t, n;
	int i;
	scanint(f[0]);
	REP(tc, t){
		scanint(f[0]);
		scanint(f[1]);
		scanint(f[2]);
		scanint(f[3]);
		scanint(f[4]);
		scanint(n);
		if (n<5)
			printf("%lld\n", f[n]);
		else {
			n -= 4;
			i = 4;
			while (i++, n--)
				f[i % 10] = (f[(i - 1) % 10] + f[(i - 2) % 10] + f[(i - 3) % 10] + 2 * f[(i - 4) % 10] + f[(i - 5) % 10]) % MOD;
			printf("%lld\n", f[--i % 10]);
		}
	}
	sp;
	return 0;
}