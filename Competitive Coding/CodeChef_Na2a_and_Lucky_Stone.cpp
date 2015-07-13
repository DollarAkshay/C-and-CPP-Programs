/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/JULY15/problems/LCKYST

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
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(x) make_pair(x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int has5(ll int n){
	while (n){
		if (n % 10 == 5)
			return 1;
		if (n % 10 != 0)
			return 0;
		else 
		n /= 10;
	}
	return 0;
}

int main(){

	ll int t, n;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		while (has5(n))
			n *= 4;
		printf("%lld\n", n);
	}
	return 0;
}

//Solved