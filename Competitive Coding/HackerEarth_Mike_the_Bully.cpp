
//http://www.hackerearth.com/problem/algorithm/mike-the-bully-3/

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

int p[100001], sum[100001];

void seiv(){
	MS1(p);
	MS0(sum);
	p[0] = p[1] = 0;
	ll int i, j, k;
	for (i = 2; i <= 100000; i++){
		if (p[i]){
			for (j = i*i; j <= 100000; j += i){
				p[j] = 0;
			}
		}
	}
	REP(k, 100001){
		if (p[k]){
			int isSum = 0;
			for (i = 2, j = k - 2; i<j; i++, j--){
				if (p[i] && p[j]){
					isSum = 1;
					break;
				}
			}
			sum[k] = isSum ? 1 : 0;
		}
	}
}


int main(){
	seiv();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		FOR(i, 5, n)
		if (sum[i])
			printf("%d ", i);
		printf("\n");
	}
	return 0;
}

//Solved 100/100

