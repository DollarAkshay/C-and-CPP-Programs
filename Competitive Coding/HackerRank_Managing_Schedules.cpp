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

struct Flight{ 
	int dest, s, e; 
};

vector<int> ans[2];
vector<Flight> g[200000];

int start = 0, curtime = 0;


void findFlights(int n){

	if (n == 4){
		int s = ans[0].size();
		if (s == 0 || (start > ans[0][s - 1] && curtime < ans[1][s - 1])){
			ans[0].push_back(start);
			ans[1].push_back(curtime);
		}
		return;
	}

	int size = g[n].size();
	REP(i, size){
		if (g[n][i].s > curtime){
			if (n == 1)
				start = g[n][i].s;
			int temp = curtime;
			curtime = g[n][i].e;
			findFlights(g[n][i].dest);
			curtime = temp;

		}
	}
}

int main(){

	int n, k;
	scanf("%d", &n);
	FOR(i, 1, n){
		scanf("%d", &k);
		REP(j, k){
			int h1, m1, h2, m2, y;
			scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &y);
			g[i].push_back({ y, h1 * 60 + m1, h2 * 60 + m2 });
		}
	}
	findFlights(1);

	int s = ans[0].size();
	printf("%d\n", s);
	REP(i, s){
			printf("%02d:%02d %02d:%02d\n", ans[0][i] / 60, ans[0][i] % 60, ans[1][i] / 60, ans[1][i] % 60);
	}
	sp;
	return 0;
}

//Partially Solved