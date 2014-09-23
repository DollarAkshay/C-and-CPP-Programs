
//http://www.hackerearth.com/problem/algorithm/find-the-nth-prime/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
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

	ll n, p = 1;
	ll a[1000];
	cin >> n;
	a[0] = 2;
	for (int i = 2; p<n; i++){
		int isPrime = 1;
		REP(j, p){
			if (i%a[j] == 0){
				isPrime = 0;
				break;
			}
		}
		isPrime ? a[p++] = i : 0;
	}
	cout << a[--n]<<endl;
	sp;
}
