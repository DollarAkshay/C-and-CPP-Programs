/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/LKS/

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

int p[500], w[500];
int DP[2][2000001];

int main(){

	int k, n;
	scanf("%d%d", &k, &n);
	assert(n<=500);
	REP(i, n)
		scanf("%d%d", &p[i], &w[i]);
	

	REP(i, n){
		if (i%2==0){
			REP(j, k+1){
				if (j<w[i])
					DP[1][j] = DP[0][j];
				else
					DP[1][j] = max(DP[0][j], DP[0][j-w[i]]+p[i]);
			}
		}
		else{
			REP(j, k+1){
				if (j<w[i])
					DP[0][j] = DP[1][j];
				else
					DP[0][j] = max(DP[1][j], DP[1][j-w[i]]+p[i]);
			}
		}
	}
	printf("%d\n", DP[n%2][k]);
	sp;
	return 0;
}

//Solved