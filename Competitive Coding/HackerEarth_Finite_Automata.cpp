
//http://www.hackerearth.com/be-coder/algorithm/finite-automata/

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

	int t, n;
	scanf("%d", &n);
	REP(i, n){
		printf("%d %d %d\n", i, i * 2 % n, (i * 2 + 1) % n);
	}
	return 0;
}

//Solved