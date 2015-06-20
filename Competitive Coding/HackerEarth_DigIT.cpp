/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/june-clash-15/algorithm/digit/

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

int digsum(ll int n){
	int sum = 0;
	while (n){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(){

	ll int a, b;
	int x, y, k;
	scanf("%lld%lld%d%d%d", &a, &b, &x, &y, &k);
	
	ll int i = a, c = 0;;
	if (i%k != 0)
		i = i - i%k + k;
	for (; i <= b; i+=k){
		int sum = digsum(i);
		if (sum >= x && sum <= y)
			c++;
	}
	printf("%lld\n", c);
	sp;
}

//Partially Solved ~ TLE