
//https://www.codechef.com/ACMAMR15/problems/AMR15D

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

ll int a[100000], c[100001];

int main() {

	ll int n, q;
	scanf("%lld", &n);
	REP(i, n)
		scanf("%lld", &a[i]);
	SORT(a, n);
	REP(i, n) 
		c[i+1] = i==0?a[i]:c[i]+a[i];
	
	scanf("%lld", &q);
	REP(i, q){
		ll int k, ans=0;
		scanf("%lld", &k);
		int house = n/(1+k);
		ans = c[house];
		ll int l = house, r = n-1-house*k;
		while (l<=r) {
			ans += a[l];
			l++;
			r -= k;
		}
		printf("%lld\n", ans);
	}
	sp;

	return 0;
}

//Solved