
//http://www.hackerearth.com/codexplod-1/algorithm/ymca-bad-powers/

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

ll int sum[1000000];
int a[1000000];

void scanint(ll int &x){
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

int main(){

	ll int t, n, p, found, i, j;
	scanf("%lld", &t);
	REP(tc, t){
		found = 0;
		MS0(sum);
		scanf("%lld%lld", &n, &p);

		REP(i, n)
			scanf("%d", &a[i]);

		SORT(a, n);

		REP(i, n){
			if (i)
				sum[i] = sum[i - 1] + a[i];
			else
				sum[0] = a[0];
		}

		for (i = 0; i<n && a[i] <= p; i++){
			int cunt = 0;
			for (j = i; j<n; j++){
				if (sum[j]<p){
					cunt = 1;
					break;
				}
				if (p == sum[j] - sum[i] + a[i]){
					found = 1;
					i = j = n;
				}
			}
		}

		if (!found)
			puts("No");
		else
			puts("Yes");

	}
	return 0;
}

//Partially Solved 40/100