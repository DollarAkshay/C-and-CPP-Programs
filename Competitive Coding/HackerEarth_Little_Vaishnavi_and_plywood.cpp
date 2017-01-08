//http://www.hackerearth.com/tcetcyphers-2/algorithm/little-vaishnavi-and-plywood-1/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define ll long long
#define MOD 1000000007


int main(){

	ll int t, n, k;
	scanf("%lld", &t);
	REP(i, t){
		scanf("%lld%lld", &n, &k);
		if (n == 1)
			printf("%lld\n", k * 8);
		else if (n == 5){
			printf("%lld\n", k * 8 + 4);
		}
		else{
			if (k % 2){
				k++;
				printf("%lld\n", k * 4 - n + 1);
			}
			else{
				printf("%lld\n", k * 4 + n - 1);
			}
		}
	}
	return 0;
}

//Solved
