/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/DEC14/problems/CAPPLE

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
#define SORT(a,n) sort(begin(a),end(a))
#define SORTR(a,n) sort(rbegin(a),rend(a))
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
#define gc getchar_unlocked
struct Edge{ int v, w; };

int a[10005];

int comp(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}


int allEqual(int n){

	REP(i,n-1){
		if (a[i] != a[i + 1]) return 0;
	}
	return 1;

}


int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n){
			scanf("%d", &a[i]);
		}
		qsort(a, n, sizeof(int), comp);
		int i, k;
		for (i = 1; !allEqual(n); i++){
			for (k = 1; a[k - 1] == a[k]; k++);
			REP(j, k){
				a[j] = a[n - j - 1];
			}
			qsort(a, n, sizeof(int), comp);
		}
		printf("%d\n", i);
	}
	return 0;
}

//Partially Solved ~ TLE