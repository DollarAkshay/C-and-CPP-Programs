
//http://www.spoj.com/problems/PRIME1/

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
#define gc getchar
#define MAX 1000000000


char primes[MAX];

void seiv(){
	MS1(primes);
	long int i, j;
	primes[0] = primes[1] = 0;
	int lim = sqrt(MAX);
	for (i = 2; i<=lim; i++){
		if (primes[i]){
			for (j = i*i; j<MAX; j += i){
				if (primes[j])
					primes[j] = 0;
			}
		}
	}
	cout << "done";
}

void scanint(ll int &x){
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

int main(){

	seiv();
	ll int t, n,m;
	scanf("%lld", &t);
	REP(tc, t){
		scanint(m);
		scanint(n);
		FOR(i,m,n)
			if (primes[i])
				printf("%lld\n", i);
			printf("\n");
	}
	return 0;
}

// Not Solved ~ TLE