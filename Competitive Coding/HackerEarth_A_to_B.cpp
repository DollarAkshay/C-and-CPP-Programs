
//http://www.hackerearth.com/target-hiring-challenge/algorithm/a-to-b-1/

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
#define gc getchar_unlocked

void scanint(ll int &x)
{
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}


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

	ll int t, n, q, type, id, v;
	ll int a[100000], b;
	ll int prod = 1;

	scanint(n);
	REP(i, n){
		scanint(a[i]);
		prod = (prod*a[i]) % MOD;
	}


	scanint(q);
	REP(i, q){
		scanint(type);
		if (type == 0){
			scanint(id);
			scanint(v);
			id--;
			if (prod){
				prod = (prod * invert_mod(a[id], MOD) % MOD) % MOD;
				a[id] = v;
				prod = (prod*a[id]) % MOD;
			}
			else{
				a[id] = v;
				if (v){
					REP(i, n)
						prod = (prod*a[i]) % MOD;
				}
				else
					prod = 0;
			}
		}
		else{
			scanint(id);
			id--;
			if (1)
				printf("%d\n", (prod*invert_mod(a[id], MOD) % MOD) % MOD);
			else{
				b = 1;
				REP(i, n){
					if (i != id)
						b = (b*a[i]) % MOD;
				}
				printf("%d\n", b);
			}

		}
	}
	return 0;
}

//Partially Solved 50/100

