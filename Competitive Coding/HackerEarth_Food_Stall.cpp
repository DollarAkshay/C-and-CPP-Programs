
//http://www.hackerearth.com/codeforgoal/algorithm/food-stall/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
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

int main(){

	ll int t, n, d, a[100005];
	ll int pairs;
	scanf("%lld", &t);
	REP(tc, t){
		pairs = 0;
		scanf("%lld%lld", &n, &d);
		assert(n>1);
		REP(i, n)
			scanf("%lld", &a[i]);

		SORT(a, n);
		for (int i = 0, j = 1; j<n;){
			if (a[j] - a[i] <= d){
				i = j + 1;
				j = i + 1;
				pairs++;
			}
			else{
				i++;
				j++;
			}
		}
		printf("%lld\n", pairs);

	}
	return 0;
}

//Solved