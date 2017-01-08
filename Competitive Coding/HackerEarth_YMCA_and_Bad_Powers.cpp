
//http://www.hackerearth.com/codexplod-1/algorithm/ymca-bad-powers/
//Google Interview Question : http://www.geeksforgeeks.org/find-subarray-with-given-sum/

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

ll int arr[1000005];


int main(){

	ll int t, n, p, sum, start, found;
	scanf("%lld", &t);
	REP(tc, t){

		scanf("%lld%lld", &n, &p);

		REP(i, n)
			scanf("%lld", &arr[i]);

		sum = found = start = 0;

		FOR(i, 0, n){
			sum += arr[i];
			while (sum>p && start<i)
				sum -= arr[start++];
			if (sum == p){
				found = 1;
				break;
			}
		}
		puts(found ? "Yes" : "No");
	}
	return 0;
}

//Solved