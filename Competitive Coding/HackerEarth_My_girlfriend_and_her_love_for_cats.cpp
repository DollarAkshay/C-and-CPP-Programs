
//http://www.hackerearth.com/problem/algorithm/my-girlfriend-and-her-love-for-cats-1/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


int compare(const void * a, const void * b)
{
	return (*(int*)b - *(int*)a);
}


int main(){

	int t, n;
	ll int sum = 0;;
	int s[1000000], c[1000000];
	scanf("%lld", &n);
	REP(i, n)
		scanf("%d", &s[i]);
	REP(i, n)
		scanf("%d", &c[i]);
	qsort(c, n, sizeof(int), compare);
	qsort(s, n, sizeof(int), compare);
	REP(i, n)
		sum = sum + (ll int)s[i] * c[i];

	printf("%lld\n", sum);
	return 0;
}

// Solved : 