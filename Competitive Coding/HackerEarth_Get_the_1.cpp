
//http://www.hackerearth.com/problem/algorithm/get-the-1/description/

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

int sum_sqr(ll int n){

	int res = 0;
	while (n){
		res += (n % 10)*(n % 10);
		n /= 10;
	}
	return res;
}


int main(){

	ll int t, n, i;
	ll int sum[1000000];
	scanf("%lld", &t);
	REP(tc, t){
		i = 0;
		scanf("%lld", &n);
		int uniq = 1;
		while (uniq){
			n = sum_sqr(n);
			if (n == 1){
				printf("Case #%d:YES\n", tc + 1);
				break;
			}

			REP(j, i){
				if (sum[j] == n){
					printf("Case #%d:NO\n", tc + 1);
					uniq = 0;
					break;
				}
			}
			sum[i++] = n;
		}
	}
	return 0;
}

//Solved