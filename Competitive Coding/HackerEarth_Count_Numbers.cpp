/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.hackerearth.com/december-easy-challenge-1/algorithm/count-numbers-7/

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

int p[10];

int multiples(int n, int a, int b){

	int res = b / n - a / n;
	if (a%n == 0) res++;
	return res;

}


int mult(int a, int b, int k){

	int res = 0, lim = pow((double)2, (double)k) - 1;
	FOR(i, 1, lim){
		int n = i, k = 0, pop = 0, big = 0;
		ll int number = 1;
		while (n){
			if (n % 2){
				number *= p[k];
				pop++;
			}
			if (number > b){
				big = 1;
				break;
			}
			n >>= 1;
			k++;
		}
		if (!big){
			int mul = multiples(number, a, b);
			res += pop % 2 ? mul : -mul;
		}
	}

	return res;

}

int main(){

	int k, t, a, b;
	scanf("%d%d", &k, &t);
	REP(i, k) scanf("%d", &p[i]);
	SORT(p, k);
	REP(i, t){
		scanf("%d%d", &a, &b);
		printf("%d\n", mult(a, b, k));
	}
	sp;
	return 0;
}

//Solved