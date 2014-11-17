
//http://www.hackerearth.com/problem/algorithm/rest-in-peace-21-1/

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

int main(){

	int t, n,ans;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		ans = 1;
		if (n % 21 == 0) ans = 0;
		else
		while (n){
			if (n % 100 == 21){
				ans = 0;
				break;
			}
			n /= 10;
		}
		puts(ans ? "The streak lives still in our heart!" : "The streak is broken!");
	}
	return 0;
}

// Solved