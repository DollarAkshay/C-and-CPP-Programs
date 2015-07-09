/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/w16/challenges/devu-and-lucky-numbers

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

ll int perm[101][101][101];
ll int DP[101][101][101];

void Permutations_3D(){

	perm[0][0][0]=1;

	FOR(i, 1, 100)
		perm[i][0][0] = perm[0][i][0] = perm[0][0][i] = 1;

	FOR(i, 1, 100){
		FOR(j, i, 100){
			ll int pi = 0, pj = 0;
			if (i - 1 >= 0)
				pi = perm[0][i - 1][j];
			if (j - 1 >= 0)
				pj = perm[0][i][j - 1];
			perm[i][j][0] = perm[j][i][0] = perm[0][i][j] = perm[0][j][i] = perm[i][0][j] = perm[j][0][i] = (pi + pj)%MOD;
		}
	}


	FOR(i, 1, 100){
		FOR(j, i, 100){
			FOR(k, j, 100){
				ll int pi = 0, pj = 0, pk = 0;
				if (i - 1 >= 0)
					pi = perm[i - 1][j][k];
				if (j - 1 >= 0)
					pj = perm[i][j - 1][k];
				if (k - 1 >= 0)
					pk = perm[i][j][k - 1];
				perm[i][j][k] = perm[i][k][j] =
					perm[j][i][k] = perm[j][k][i] =
					perm[k][i][j] = perm[k][j][i] = (pi + pj + pk)%MOD;
			}
		}
	}


}

void preCalc(){

	Permutations_3D();

	FOR(i, 0, 100){
		FOR(j, 0, 100){
			FOR(k, 0, 100){
				ll int di = 0, dj = 0, dk = 0;
				ll int pi = 0, pj = 0, pk = 0;
				if (i - 1 >= 0){
					pi = perm[i-1][j][k];
					di = DP[i-1][j][k];
				}
				if (j - 1 >= 0){
					pj = perm[i][j-1][k];
					dj = DP[i][j-1][k];
				}
				if (k- 1 >= 0){
					pk = perm[i][j][k-1];
					dk = DP[i][j][k-1];
				}
				DP[i][j][k] = (((di+dj+dk)*10)%MOD + pk*4%MOD + pj*5%MOD  + pi*6%MOD)%MOD ;
			}
		}
	}


}

int main(){

	preCalc();
	int x,y,z;
	ll int ans = 0;

	scanf("%d%d%d",&x,&y,&z);

	FOR(i, 0, z)
		FOR(j, 0, y)
			FOR(k, 0, x)
				ans = (ans + DP[i][j][k])%MOD;

	printf("%lld", ans);
	return 0;
}

//Pre Test Passed :D But I think its solved !!