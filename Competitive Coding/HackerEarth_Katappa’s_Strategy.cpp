/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codification/algorithm/katappas-strategy/

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int nu[100000], de[100000];

int gcd(int a, int b){

	int c;
	while (a != 0) {
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

pii max_frac(pii a, pii b){

	if ((ll int)a.first*b.second > (ll int)b.first*a.second)
		return a;
	else
		return b;

}

pii max_btw(int l, int r){

	pii maxf = mp(0, 1), curf = mp(0, 0);
	FOR(i, l, r){
		curf.first += nu[i];
		curf.second += de[i];
		maxf = max_frac(maxf, curf);
	}
	return maxf;
}

void print_frac(pii maxf){

	pii a = maxf;
	int div = gcd(a.first, a.second);
	a.first /= div;
	a.second /= div;
	printf("%d/%d\n", a.first, a.second);

}

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n)
			scanf("%d/%d", &nu[i], &de[i]);
		
		pii maxf = max_btw(0, n-1);
		print_frac(maxf);

		REP(i,n-1){
			if (nu[i]<de[i]){
				maxf = max_btw(i+1, n-1);
				print_frac(maxf);
			}
			else{
				maxf.first -= nu[i];
				maxf.second -= de[i];
				if (maxf.first ==0 || maxf.second==0)
					maxf = max_btw(i+1, n-1);
				print_frac(maxf);
			}
		}
		printf("\n");
	}
	sp;
	return 0;
}

//