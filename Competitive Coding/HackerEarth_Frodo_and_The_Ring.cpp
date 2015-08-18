/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/epiphany-5/algorithm/frodo-and-ring/

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
#include <functional>

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

char grid[200][200];
ll int DP[200][200];
char calc[200][200];

ll int eg(int i, int j){

	if (j<0 || i<0)
		return -1000000000000000000;

	if (calc[i][j])
		return DP[i][j];

	if (grid[i][j]=='T')
		DP[i][j] = 150 + max(eg(i-1, j), eg(i, j-1));
	else if (grid[i][j]=='D')
		DP[i][j] = -100 + max(eg(i-1, j), eg(i, j-1));
	else
		DP[i][j] = max(eg(i-1, j), eg(i, j-1));

	calc[i][j] = 1;
	return DP[i][j];

}


int main(){

	int t, n, m;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &m);
		getchar();
		REP(i, n){
			REP(j, m){
				scanf("%c", &grid[i][j]);
				getchar();
			}
		}

		ll int ans = eg(n-1,m-1);
		if (ans<0)
			ans = -1;
		printf("%lld\n", ans);
		MS0(calc);
	}
	sp;
	return 0;
}

//