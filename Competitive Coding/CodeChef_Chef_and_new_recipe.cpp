/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/MAY15/problems/CHEFRP

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

bool comp(int a, int b){
	return a > b;
}

int main(){

	int t, n, m,sum;
	int a[100000];

	scanf("%d", &t);
	REP(tc, t){
		sum = 0;
		m = 10000;
		scanf("%d", &n);
		REP(i, n){
			scanf("%d", &a[i]);
			sum += a[i];
			m = min(a[i], m);
		}
		if (m < 2)
			printf("-1\n");
		else{
			printf("%d\n", sum - m + 2);
		}

	}
	return 0;
}

//Solved