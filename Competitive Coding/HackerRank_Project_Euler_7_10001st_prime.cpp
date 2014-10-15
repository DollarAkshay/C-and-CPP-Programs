

//https://www.hackerrank.com/contests/projecteuler/challenges/euler007

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

#define MAX 10000001

char primes[MAX];
ll a[700000];

void siev(){
	MS1(primes);
	long int i, j;
	primes[0] = primes[1] = 0;
	for (i = 2; i<MAX; i++){
		if (primes[i]){
			for (j = i*i; j<MAX; j += i){
				if (primes[j])
					primes[j] = 0;
			}
		}
	}
	int x = 0;
	for (i = 2; i<MAX; i++){
		if (primes[i]){
			a[x++] = i;
		}
	}
}

int main(){
	siev();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		cout << a[n - 1] << endl;
	}
	return 0;
}

//Solved