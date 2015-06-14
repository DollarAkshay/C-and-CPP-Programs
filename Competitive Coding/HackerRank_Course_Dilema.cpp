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

int g[1000][1000], v[1000], n;

int canTake(int x){

	if (v[x])
		return 0;
	REP(i, n){
		if (g[i][x] == 1)
			return 0;
	}
	return 1;

}

void topo(){

	int sem = 0, c = 0;

	while (c < n){
		vector<int>remov;
		REP(i, n){
			if (canTake(i)){
				remov.push_back(i);
				c++;
				v[i] = 1;
			}
		}
		if (remov.size() == 0){
			printf("Never Ends\n");
			return;
		}
		else{
			REP(k, remov.size()){
				REP(j, n)
					g[remov[k]][j] = 0;
			}
		}
		sem++;
	}
	printf("%d semester(s)\n", sem);

}


int main(){

	int t, r;

	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &r);
		REP(i, r){
			int u, v;
			scanf("%d%d", &u, &v);
			g[v][u] = 1;
		}
		printf("Case %d: ", tc + 1);
		topo();
		REP(i, n){
			MS0(g[i]);
			v[i] = 0;
		}
	}
	return 0;
}

//Solved