/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/BYTESM2/

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
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int r, c, a[100][100];
int DP[100][100];

int ans;

int DFS_DP(int s, int level){


	if (DP[level-1][s]!=-1)
		return DP[level-1][s];

	if (level==r)
		return a[level-1][s];

	int left=0, down=0, right=0;

	if (s+1<c)
		right = a[level-1][s] + DFS_DP(s+1, level+1);

	down = a[level-1][s] + DFS_DP(s, level+1);

	if (s-1>=0)
		left = a[level-1][s] + DFS_DP(s-1, level+1);

	DP[level-1][s] = max(max(left, right), down);

	return DP[level-1][s];

}

int main(){

	int t;
	scanf("%d", &t);
	REP(tc, t){
		ans = 0;
		scanf("%d%d", &r, &c);
		REP(i, r){
			REP(j, c){
				scanf("%d", &a[i][j]);
				DP[i][j] = -1;
			}
		}
		REP(i, c){
			ans = max(ans,DFS_DP(i,1));
		}
		printf("%d\n", ans);
	}
	sp;
	return 0;
}

//Solved