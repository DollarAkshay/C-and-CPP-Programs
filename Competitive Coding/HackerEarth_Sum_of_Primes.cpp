
//http://www.hackerearth.com/tcetcyphers-4/algorithm/sum-of-primes/

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
struct Edge{ int v, w; };

int p[1000001];
ll int sum[1000001];

void seiv(){

	MS1(p);
	long int i, j;
	p[0] = p[1] = 0;
	int lim = sqrt(1000001);
	for (i = 2; i <= lim; i++){
		if (p[i]){
			for (j = i*i; j<1000001; j += i){
				if (p[j])
					p[j] = 0;
			}
		}
	}
	sum[0] = 0;
	FOR(i, 1, 1000000)
		sum[i] = p[i] ? i + sum[i - 1] : sum[i - 1];
}

int isPrime(ll int x){
	if (x<2)
		return 0;
	else if (x == 2)
		return 1;
	int lim = sqrt(x);
	FOR(i, 2, lim)
	if (x%i == 0)
		return 0;
	return 1;
}

int main(){

	seiv();
	int t, l, r;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &l, &r);
		ll int s = sum[r] - sum[l];
		if (p[l])
			s += l;
		if (s <= 1000000)
			puts(p[s] ? "YES" : "NO");
		else
			puts(isPrime(s) ? "YES" : "NO");
	}
	return 0;
}

//Solved