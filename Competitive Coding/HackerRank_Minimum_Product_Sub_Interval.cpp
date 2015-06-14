/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/indeed-prime-challenge/challenges/minimum-product-sub-interval

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

int main(){

	int q, n;
	register int a[100001];
	scanf("%d%d", &n, &q);
	FOR(i, 1, n)
		scanf("%d", &a[i]);

	REP(i, q){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1){
			int m = a[y], pos = y,maxl=0;
			FOR(j, y, z){
				if (a[j] < m){
					m = a[j];
					pos = j;
					if (m == 0)
						break;
				}
				if (m == 1 && a[j] == 1){
					int len = 0,u=j;
					while (j <= z && a[j] == 1){
						len++;
						j++;
					}
					if (len > maxl){
						maxl = len;
						pos = u;
					}
				}
			}
			if (m == 0)
				printf("%d %d %d\n", 0, y, z);
			else if (m == 1)
				printf("%d %d %d\n", 1, pos, pos + maxl - 1);
			else
				printf("%d %d %d\n", m, pos, pos);
		}
		else
			a[y] = z;
	}
	return 0;
}

//Solved