//http://www.hackerearth.com/problem/algorithm/modify-sequence/description/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,n-1)
#define ll long long


int main(){
	int n, a, b;
	scanf("%d%d", &n, &a);
	REP(i, n - 1){
		scanf("%d", &b);
		if ((a = b - a)<0)
			break;
	}
	puts(a ? "NO" : "YES");
	return 0;
}

//Solved








