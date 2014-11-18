
//http://www.codechef.com/MTRX2014/problems/JERYFIBO

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
#define gc getchar_unlocked
struct Edge{ int v, w; };

ll int fib[50],f;

void preCalc(){
	fib[0] = 0;
	fib[1] = 1;
	for (f=2; fib[f - 1] < 1000000000;f++)
		fib[f] = fib[f- 1] + fib[f - 2];
}

int bsearch(ll int a[], int n,ll int key){

	int low = 0, high = n, mid;
	while (low <= high){
		mid = (high + low) / 2;
		if (a[mid] == key)
			return 1;
		else if (key > a[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return 0;
}


int main(){

	
	preCalc();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		puts(bsearch(fib,f,n)?"is fibo":"not fibo");
	}
	return 0;
}

//Solved