
//http://www.hackerearth.com/problem/algorithm/will-rick-survive-or-not-2/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>

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

void scanint(int &x)
{
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}



int main(){
	int t, n, i, j;
	int a[100005];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n)
			scanint(a[i]);
		SORT(a, n);
		for (i = 0, j = 0; i<n; i++, i % 6 ? 0 : j++){
			if (a[i] - i - j <= 0)
				break;
		}
		if (i == n)
			printf("Rick now go and save Carl and Judas\n");
		else
			printf("Goodbye Rick\n%d\n", i);
	}
	return 0;
}

//Solved 
