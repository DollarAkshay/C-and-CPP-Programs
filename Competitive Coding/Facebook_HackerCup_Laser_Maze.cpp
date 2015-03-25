/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

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

char board[101][101];

int main(){

	int t, n,m;
	scanf("%d", &t);
	REP(tc, t){
		int sx, sy, gx, gy;
		scanf("%d%d", &n, &m);
		REP(i, n){
			scanf("%s", board[i]);
			if (strchr(board[i], 'S')){
				sx = strchr(board[i], 'S') - board[i];
				sy = i;
			}
			if (strchr(board[i], 'G')){
				gx = strchr(board[i], 'G') - board[i];
				gy = i;
			}
		}

		
		
		
	}
	return 0;
}

//