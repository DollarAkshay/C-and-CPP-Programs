/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/icecream-parlor

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

int a[10000];

int main(){

	int t, m,n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &m);
		scanf("%d", &n);
		REP(i, n) scanf("%d", &a[i]);
		REP(i, n){
			FOR(j, i + 1, n - 1){
				if (a[i] + a[j] == m){
					printf("%d %d\n", i + 1, j + 1);
					i = n;
					break;
				}
			}
		}
	}
	return 0;
}

//Solved