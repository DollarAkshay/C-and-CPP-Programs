
//http://www.hackerearth.com/be-coder/algorithm/big-values/

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


unsigned long long invert_mod(unsigned long long a, unsigned long long p) {
	unsigned long long ne = 1, old = 0, q = p, r, h;
	int pos = 0;
	while (a > 0) {
		r = q%a;
		q = q / a;
		h = q*ne + old;
		old = ne;
		ne = h;
		q = a;
		a = r;
		pos = !pos;
	}
	return pos ? old : (p - old);
}


int main(){

	int inv[] = { 1, 1000000005, 4, 999999999, 16, 999999975, 64 };


	unsigned ll int x, i, n, r = 6;
	x = i = 1;
	scanf("%llu", &n);
	r = n - r>r ? n - r : r;
	while (n - r>0){
		x = ((x%MOD)*(n%MOD)) % MOD;
		x = ((x%MOD) * (invert_mod(i, MOD) % MOD)) % MOD;
		n--;
		i++;
	}
	printf("%llu\n", x%MOD);
	return 0;
}

//Solved