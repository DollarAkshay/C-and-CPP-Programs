/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/the-grid-search

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

char mat[1000][1000], pat[1000][1000];
int t, n, R, C, r, c;

int search(){

	FOR(i, 0, R - r){
		FOR(j, 0, C - c){
			int found = 1;
			FOR(k, i, i + r - 1){
				FOR(l, j, j + c - 1){
					if (mat[k][l] != pat[k-i][l-j]){
						found = 0;
						k = i + r;
						break;
					}
				}
			}
			if (found)
				return 1;
		}
	}
	return 0;

}

int main(){

	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &R, &C);
		REP(i, R) cin >> mat[i];
		scanf("%d%d", &r, &c);
		REP(i, r) cin >> pat[i];
		puts(search() ? "YES" : "NO");	
	}
	return 0;
}

//Solved