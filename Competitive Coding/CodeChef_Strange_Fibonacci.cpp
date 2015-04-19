/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/SPT2015/problems/SPIT05

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
#define MOD 10000000000000
#define LIM 15000000000000
#define gc getchar_unlocked
struct Edge{ int v, w; };

int main(){

	ll int n, a = 0, b = 1,c,i=2;
	scanf("%lld", &n);
	if (n < 2)
		printf("%lld", n);
	else{
		while (i<LIM){
			c = (a + b)%MOD;
			a = b;
			b = c;
			if (n == b){
				printf("%lld", i);
				return 0;
			}
			i++;
		}
	}
	return 0;
}

//