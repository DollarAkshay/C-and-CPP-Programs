
//https://www.hackerrank.com/contests/codigo-mistreo/challenges/that-big-number

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
#define MOD 10000007
#define gc getchar_unlocked
struct Edge{ int v, w; };

int g[10000];


void pre(){
	g[4] = g[1] = 1;
	g[3] = g[2] = 3;
	FOR(i, 5, 10000 - 1){
		g[i] = (g[i - 1] + 3 * g[i - 2] + 3 * g[i - 3] + g[i - 4])%MOD;
	}
}




void multiply4x4(int a[4][4], int b[4][4]){
	ll int c[4][4];
	//Multiply A and B and store it in C
	REP(i, 4){
		REP(j, 4){
			c[i][j] = 0;
			REP(k, 4)
				c[i][j] = (c[i][j] + (ll int)a[i][k] * b[k][j]) % MOD;
		}
	}

	// Copy Matrix C into A
	REP(i, 4)
		REP(j, 4)
			a[i][j] = (int)c[i][j];
}

void multiply4x1(int a[4][4], int b[4]){

	ll int c[4];
	//Multiply A and B and store it in C
	REP(i, 4){
		REP(j, 1){
			c[i]= 0;
			REP(k, 4)
				c[i] = (c[i] + (ll int)a[i][k]*b[k]) % MOD;
		}
	}

	// Copy Matrix C into B
	REP(i, 4)
		REP(j, 1)
			b[i] = (int)c[i];
}


void power(int G[4][4],ll int n){

	if (n == 0 || n == 1)
		return;
	int A[4][4] = { { 1, 3, 3, 1 }, 
					{ 1, 0, 0, 0 }, 
					{ 0, 1, 0, 0 }, 
					{ 0, 0, 1, 0 } };

	power(G, n / 2);
	multiply4x4(G,G);

	if (n % 2 != 0)
		multiply4x4(G, A);
}


int seriesG(ll int n){

	if (n == 1 || n == 4)
		return 1;
	if (n == 2 || n == 3)
		return 3;

	int G[4][4] = { { 1, 3, 3, 1 },
					{ 1, 0, 0, 0 },
					{ 0, 1, 0, 0 },
					{ 0, 0, 1, 0 } };
	int C[4] = { 1,3,3,1 };

	n -= 4;

	power(G, n);
	multiply4x1(G, C);
	return C[0];
}



int main(){

	pre();
	ll int t, n;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		printf("%d\n", seriesG(n));
	}
	return 0;
}

//Solved 