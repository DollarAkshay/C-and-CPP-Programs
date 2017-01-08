
//http://www.hackerearth.com/be-coder/algorithm/dushhera-special/

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

	int t, n, k;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &k);
		int c = 0;
		for (int i = k + 1; c<n; c++, i += (k + 1)){
			printf("%d ", i);
		}
		cout << endl;
	}
	return 0;
}

//Solved