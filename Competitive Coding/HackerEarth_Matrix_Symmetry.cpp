//http://www.hackerearth.com/problem/algorithm/matrix-symmetry/

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

	int t, n, i, j, k, l;
	char a[50][50];
	scanf("%d", &t);
	REP(l, t){
		scanf("%d", &n);
		int h = 1, v = 1;
		REP(i, n)
			scanf("%s", a[i]);
		//Vertical Symmetry
		REP(k, n){
			for (i = 0, j = n - 1; i<j; i++, j--){
				if (a[k][i] != a[k][j]){
					v = 0;
					k = n;
					break;
				}
			}
		}
		//Horizontal Symmetry
		REP(k, n){
			for (i = 0, j = n - 1; i<j; i++, j--){
				if (a[i][k] != a[j][k]){
					h = 0;
					k = n;
					break;
				}
			}
		}
		puts(h && v ? "BOTH" : h ? "HORIZONTAL" : v ? "VERTICAL" : "NO");
	}
	return 0;
}

//Solved 