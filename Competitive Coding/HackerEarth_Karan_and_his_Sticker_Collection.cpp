
//http://www.hackerearth.com/problem/algorithm/karan-and-his-sticker-collection/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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

void scanint(ll int &x){

	char c = gc();
	x = 0;
	while (c<'0' || c>'9')c = gc();
	while (c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = gc();
	}

}



int main(){

	ll int t, n,c=0;
	scanf("%lld", &t);
	while (t--){ scanint(n); if (n < 300000000)c++;}
	cout << c;
	return 0;
}

// Solved