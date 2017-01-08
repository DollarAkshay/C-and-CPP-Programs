
//https://www.hackerrank.com/contests/inscription2014/challenges/lucys-dish

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

int f[1001];

int main(){


	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		f[n]++;
	}
	int max = 0, c = 0, pos;
	REP(i, t){
		if (f[i]>max){
			c = 1;
			max = f[i];
			pos = i;
		}
		else if (f[i] == max){
			c++;
		}
	}
	if (c>1)
		puts("-1");
	else
		printf("%d\n", pos);
	return 0;
}

//Solved