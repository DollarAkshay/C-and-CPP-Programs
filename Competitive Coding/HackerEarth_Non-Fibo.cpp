/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/non-fibo/

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

vector<ll int>fib;

void pre(){

	ll int a = 1, b = 2;
	fib.push_back(1);
	fib.push_back(2);
	while (a + b < 1000000000000000000){
		b = a + b;
		a = b - a;
		fib.push_back(b);
	}
}

int isFib(ll int n){

	int size = fib.size();
	REP(i, size){
		if (fib[i] == n)
			return 1;
		if (fib[i] > n) return 0;
	}
	return 0;
}


ll int nonfib(ll int n){

	ll int res = n,size = fib.size(),c=0;
	REP(i, size){
		if (fib[i] <= n)
			c++;
		else
			break;
	}
	while (c != 0){
		res++;
		if (isFib(res))
			continue;
		else 
			c--;
	}
	return res;
}

int main(){

	pre();
	ll int t, n;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		printf("%lld\n", nonfib(n));
	}
	sp;
	return 0;
}

//Solved