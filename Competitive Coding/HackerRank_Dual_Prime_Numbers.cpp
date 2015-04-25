/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/tech-weekend-online-coding/challenges/dual-prime-1

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

#define MAX 1000001
int p[MAX], dual[MAX];


int sum(int n){

	int res = 0;
	while (n){
		res += n % 10;
		n /= 10;
	}
	return res;
}

void seiv(){

	MS1(p);
	p[0] = p[1] = 0;
	ll int i, j;
	int lim = sqrt(MAX);
	for (i = 2; i <= lim; i++){
		if (p[i]){
			for (j = i*i; j<MAX; j += i)
				p[j] = 0;
		}
	}
	dual[0] = 0;
	FOR(i, 1, MAX - 1){
		if (p[i] && p[sum(i)])
			dual[i] = dual[i - 1] + 1;
		else
			dual[i] = dual[i - 1];
	}

}


int main(){

	seiv();
	int t, n, m;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &m, &n);
		assert(n <= 1000000 && m <= 1000000);
		printf("%d\n", dual[n] - dual[m - 1]);
	}
	return 0;
}

//Solved