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

int main(){

	int price[50000];
	ll int t, n, profit, shares;
	scanf("%lld", &t);
	REP(tc, t){
		profit = shares = 0;
		scanf("%lld", &n);
		REP(i, n)
			scanf("%lld", &price[i]);
		REP(i, n - 1){
			int rise = 0;
			FOR(j, i + 1, n - 1){
				if (price[j]>price[i]){
					rise = 1;
					break;
				}
			}
			if (rise){
				profit -= price[i];
				shares++;
			}
			else if (shares && price[i + 1] <= price[i]){
				profit += price[i] * shares;
				shares = 0;
			}

		}
		profit += price[n - 1] * shares;
		printf("%lld\n", profit);
	}
	return 0;
}