
//http://www.codechef.com/MTRX2014/problems/STIKGAME

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

int a[2000];

int main(){

	int t, n,j,i,k;
	scanf("%d", &n);
	while (n){
		REP(i, n) scanf("%d", &a[i]);
		SORT(a, n);
		int impos = 0;
		for (j = n - 1; j >= 2; j--){
			for (i = 0; i < j; i++){
				for (k = i + 1; k<j; k++){
					if (a[j]>a[i] + a[k])
						impos++;
					else
						break;
				}
			}
		}
		printf("%d\n", impos);
		scanf("%d", &n);
	}
	return 0;
}

//Solved with a O(n^3) algorithm.