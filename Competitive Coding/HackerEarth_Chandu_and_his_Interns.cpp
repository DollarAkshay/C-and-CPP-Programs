/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-monk-number-theory-i/algorithm/chandu-and-his-interns/

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

char p[10000001];

void seiv(){

	MS1(p);
	p[0] = p[1] = 0;
	ll int i, j, lim = sqrt(10000001);
	for (i = 2; i <= lim; i++){
		if (p[i]){
			for (j = i*i; j<10000001; j += i)
				p[j] = 0;
		}
	}

}

int divz(int n){

	if (p[n])
		return 0;
	int lim = sqrt(n), c = 0;
	FOR(i, 1, lim){
		if (n%i == 0){
			c++;
			if (n / i>lim)
				c++;
			if (c >= 4)
				return 1;
		}
	}
	return 0;
}

int main(){

	seiv();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		puts(divz(n) ? "YES" : "NO");
	}
	return 0;
}

//Solved