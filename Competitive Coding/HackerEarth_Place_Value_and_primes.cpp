/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.hackerearth.com/tcetcyphers-5/algorithm/place-value-and-primes/

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

char p[1000001];

void seiv(){
	MS1(p);
	long int i, j;
	p[0] = p[1] = 0;
	int lim = sqrt(1000001);
	for (i = 2; i <= lim; i++){
		if (p[i]){
			for (j = i*i; j<1000001; j += i){
				if (p[j])
					p[j] = 0;
			}
		}
	}
}


int nthprime(int n){
	if (n == 0)
		return 1;
	int c = 0;
	REP(i, 1000001){
		if (p[i])
			c++;
		if (c == n)
			return i;
	}
}

int main(){
	seiv();
	int t, m, x;
	char str[1000];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s%d%d", str, &m, &x);
		int len = strlen(str);
		REV(str, len);
		int poww = 0, c = 0;
		REP(i, len){
			if (str[i] - '0' == m){
				c++;
				poww = i;
				if (c == x)
					break;
			}
		}
		if (poww % 2 == 0)
			printf("%d\n", nthprime(m));
		else
			printf("%d\n", nthprime(poww));
	}
	return 0;
}

//Solved