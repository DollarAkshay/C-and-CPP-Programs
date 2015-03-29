/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/LTIME22/problems/CHEFANUP

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

int a[1000];

int main(){

	ll int t, n,k,l;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld%lld", &n,&k,&l);
		l--;
		REP(i, n)
			a[i] = 0;
		int i = 0;
		while (l > 0){
			a[i] = (a[i]+l)%k;
			l /= k;
			i++;
		}
		FORD(i, n - 1, 0)
			printf("%d ", a[i]+1);
		printf("\n");
	}
	return 0;
}

//Solved