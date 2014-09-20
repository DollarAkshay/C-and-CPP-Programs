//http://www.codechef.com/problems/TSORT

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

int compare(const void *a, const void* b){
	return *(int*)a - *(int*)b;
}
int main(){

	int n;
	int a[100];
	scanf("%d", &n);
	REP(i,n){
		scanf("%d", &a[i]);
	}

	qsort(a, n, sizeof(int), compare);

	REP(i, n){
		printf("%d\n", a[i]);
	}
	return 0;
}

//Solved