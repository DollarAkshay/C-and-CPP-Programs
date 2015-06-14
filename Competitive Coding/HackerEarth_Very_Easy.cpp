/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/game-of-codes-1/algorithm/very-easy/

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

int a[100001], dp[100001], pre[100000], n;

void remove(int pos){


	FOR(i, pos + 1, n)
		a[i - 1] = a[i];
	n--;
}

int LDS(){

	int m = 1, pos = 0;
	REP(i, n){
		dp[i] = 1;
		pre[i] = -1;
	}
	FOR(i, 1, n - 1){
		REP(j, i){
			if (a[j] <= a[i] && dp[j] + 1 > dp[i]){
				dp[i] = dp[j] + 1;
				pre[i] = j;
				if (dp[i] > m){
					m = dp[i];
					pos = i;
				}
			}
		}
	}
	return pos;
}

int main(){

	scanf("%d", &n);
	REP(i, n)
		scanf("%d", &a[i]);

	int turn = 0;
	while (n){
		int pos = LDS();
		while (pos != -1){
			remove(pos);
			pos = pre[pos];
		}
		turn++;
	}
	printf("%d", turn);
	sp;

	return 0;
}

//