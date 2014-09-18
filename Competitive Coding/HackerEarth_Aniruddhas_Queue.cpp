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

	ll int t, n;
	unsigned ll int a[100000], sum[100000], m;
	scanf("%lld", &t);
	REP(i, t){
		scanf("%d", &n);
		REP(j, n){
			scanf("%llu", &a[j]);
			if (j)
				sum[j] = sum[j - 1] + a[j];
			else
				sum[0] = a[0];
		}
		scanf("%llu", &m);
		m %= sum[n - 1];
		REP(j, n){
			if (sum[j] >= m){
				printf("%lld\n", j + 1);
				break;
			}
		}

	}
	return 0;
}

//Partially Solved : 70/100