/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/488/problem/A

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
#define ll __int64
#define MOD 1000000007
#define gc getchar_unlocked
struct Edge{ int v, w; };


int check8(ll n){

	n = abs(n);
	while (n){
		if (n % 10 == 8)
			return 1;
		n /= 10;
	}
	return 0;

}

int main(){

	ll t, n;
	scanf("%I64d", &n);
	t = n;
	while (!check8(++n));
	printf("%I64d\n", n - t);
	return 0;
}

//Solved 