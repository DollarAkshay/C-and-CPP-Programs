
//http://www.spoj.com/problems/PRIME1

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

int sq1 = sqrt(MAX);
int sq2 = sqrt(sq1);

char prime[MAX+5];


void seiv(){

	MS1(prime);
	ll int i, j;
	prime[0] = prime[1] = 0;

	for (i = 2; i<=sq2; i++){
		if (prime[i]){
			for (j = i*i; j<=sq1; j += i){
				if (prime[j])
					prime[j] = 0;
			}
		}
	}
}

void segmentedSeiv(int a, int b){

	int lim = sqrt(b);
	int i, j;
	for (i = 2; i <= lim; i++){
		if (prime[i]){
			for (j = a - a%i; j <= b; j += i)
				if (j>=a && prime[j] && j!=i)
					prime[j] = 0;
		}
	}

}

int main(){

	seiv();
	int t, n,m;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &m, &n);
		if (n>sq2)
			segmentedSeiv(m, n);
		FOR(i,m,n)
			if (prime[i])
				printf("%d\n", i);
		printf("\n");
	}
	return 0;
}

// Solved :D So happy