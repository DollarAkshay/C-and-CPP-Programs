//https://www.hackerrank.com/contests/codeomania/challenges/distinct-prime-factors

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

int p[1000005];
int ans[1000005];

void seiv(){
	MS1(p);
	MS0(ans);
	p[0] = p[1] = 0;
	ll int i, j;
	for (i = 2; i <= 1000004; i++){
		if (p[i]){
			ans[i] = 1;
			for (j = i*i; j <= 1000004; j += i){
				p[j] = 0;
			}
		}
	}
	for (i = 2; i <= 1000004; i++){
		if (!p[i]){
			ll int n = i;
			ll int lim = sqrt(n);
			for (j = 2; j <= i && n != 1; j++){
				if (p[j] && n%j == 0){
					ans[i]++;
					while (n%j == 0)
						n /= j;
					if (p[n]){
						ans[i]++;
						break;
					}
				}
			}
		}
	}
}




int main(){
	seiv();
	cout << "End";
	ll int t, n;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}

//Solved