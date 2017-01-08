
//http://www.hackerearth.com/problem/algorithm/ma5terminds-birthday-party/description/

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

int cool[1000001], sum[1000001];

void preCompute(){
	long long int j, i;
	for (i = 2; i <= 1000000; i++){
		if (cool[i]){
			for (j = i*i; j <= 1000000; j += i)
			if (cool[j])
				cool[j] = 0;
		}
	}
	cool[0] = 1;
	cool[1] = 0;
	cool[4] = 1;
	sum[0] = 0;
	FOR(i, 1, 1000000){
		if (cool[i] == 0)
			sum[i] = sum[i - 1] + 1;
		else
			sum[i] = sum[i - 1];
	}

}


int main(){

	MS1(cool);
	preCompute();

	int t, n, c, l, r;

	scanf("%d", &t);
	REP(tc, t){
		c = 0;
		scanf("%d%d", &l, &r);
		int ans = sum[r] - sum[l];
		if (cool[l] == 0)
			ans++;
		printf("%d\n", ans);

	}

	return 0;
}

//Solved