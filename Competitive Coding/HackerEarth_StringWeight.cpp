//http://www.hackerearth.com/epiphany-4-1/algorithm/string-weight/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define ll long long
#define MOD 1000000007


int main(){

	int t, n, l;
	char c[10005], x, y;
	char skip[26];
	int f[26];
	ll int ans;

	scanf("%d", &t);
	REP(i, t){
		MS0(f);
		ans = 0;
		scanf("%s", c);
		l = strlen(c);
		REP(j, l){
			f[c[j] - 97]++;
			ans += (c[j] - 96);
		}

		scanf("%d", &n);
		REP(j, n){
			scanf("%c%c", &x, &y);
			ans = ans - (f[y - 97] * (y - 96));
		}
		printf("%lld\n", ans);
	}
	return 0;
}

//Solved