/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-monk-searching/algorithm/discover-the-monk/

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

int a[100000];

int compareints(const void * a, const void * b){
	return (*(int*)a - *(int*)b);
}

int main(){

	int n, q, x;
	scanf("%d%d", &n, &q);
	REP(i, n)
		scanf("%d", &a[i]);
	SORT(a, n);
	REP(i, q){
		scanf("%d", &x);
		puts(bsearch(&x,a,n,sizeof(int), compareints) ? "YES" : "NO");
	}
	
	return 0;
}

//Solved