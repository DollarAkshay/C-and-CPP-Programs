
//http://www.hackerearth.com/problem/algorithm/help-out-the-indian-army/

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


struct army {
	ll int left;
	ll int right;
	char valid;
};

ll int s, e;

void scanint(ll int &x){
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

void overlap(army *a, army *b){
	if (b->left >= a->left && b->left<a->right){
		a->left = a->left<b->left ? a->left : b->left;
		if (a->left<s)
			a->left = s;
		a->right = a->right>b->right ? a->right : b->right;
		if (a->right>e)
			a->right = e;
		b->valid = 0;
	}

}



int main(){

	struct army a[100000];
	ll int x, p, n, prot = 0;
	scanf("%lld%lld%lld", &n, &s, &e);
	REP(i, n){
		scanint(x);
		scanint(p);
		a[i].left = x - p;
		a[i].right = x + p;
		a[i].valid = 1;
	}

	// O(n^2) algorithm :(
	REP(i, n){
		FOR(j, 0, n - 1){
			if (a[i].valid && a[j].valid && i != j)
				overlap(&a[i], &a[j]);
		}
	}

	REP(i, n){
		if (a[i].valid)
			prot = prot + a[i].right - a[i].left;
	}
	printf("%lld\n", e - s - prot);
	return 0;
}


//Not Solved 4/100