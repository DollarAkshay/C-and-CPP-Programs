
//http://www.codechef.com/TCFS15S/problems/LIZARDS/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
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


char a[80000];
int dp[80000];

int main(){

	int n,q,l,r;
	int rc = 0,lc=0;
	scanf("%d", &n);
	getchar();
	REP(i, n){
		scanf("%c", &a[i]);
		if (a[i] == 'R'){
			rc++;
			dp[i] = lc;
		}
		else
			dp[i] = ++lc;
	}

	scanf("%d", &q);
	REP(i, q){
		ll int ans = 0;
		scanf("%d %d", &l, &r);
		FOR(i, l, r){
			if (a[i] == 'L'){
				lc--;
				rc++;
				a[i] = 'R';
				if (i)
					dp[i] = dp[i - 1];
				else
					dp[0] = 0;
			}
			else{
				lc++;
				rc--;
				dp[i] = dp[i - 1] + 1;
				a[i] = 'L';
			}
		}
		FOR(i, r + 1, n - 1){
			if (a[i] == 'L')
				dp[i] = dp[i - 1] + 1;
			else
				dp[i] = dp[i - 1];
		}
		REP(i, n){
			if (a[i] == 'R')
				ans += (lc - dp[i]);
		}
		printf("%lld\n", ans);
		
	}
	sp;
	return 0;
}

//Not Solved