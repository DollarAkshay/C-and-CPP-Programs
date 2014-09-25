


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

	int primes[10] = {29,23,19,17,13,11,7,5,3,2};
	ll int max=0,pos,profit=0;
	int n, bag, m=0,empty;
	int p[2000], w[2000];
	scanf("%lld", &n,&w);
	REP(i, n){
		scanf("%d%d", &p[i], &w[i]);
		if (p[i] > max){
			max = p[i];
			pos = i;
		}
	}

	return 0;
}

//Incomplete