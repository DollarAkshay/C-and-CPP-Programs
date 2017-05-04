/*~~~~~~~~~~~~~~~~~~*
*                  *
* Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/codeagon/challenges/back-to-origin

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
#define MS(x,n) memset(x,n,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

vector<int> depend[20000];
vector<int> requiredBy[20000];

int install[20000], need[20000], inDeg[20000];

void findDependencies(int program) {

	if (install[program] != 1) {
		install[program] = 1;
		REP(i, depend[program].size()) {
			findDependencies(depend[program][i]);
		}
	}

}

int main() {

	int t;
	scanf("%d", &t);
	REP(tc, t) {
		int n, m;
		scanf("%d %d", &n, &m);

		MS(inDeg, 0);
		MS(install, 0);
		REP(i, n) {
			requiredBy[i].clear();
			depend[i].clear();
		}

		REP(i, n) {
			int count;
			scanf("%d", &count);
			REP(j, count) {
				int p;
				scanf("%d", &p);
				p--;
				depend[i].push_back(p);
				requiredBy[p].push_back(i);
				inDeg[i]++;
			}

		}

		REP(i, m) {
			scanf("%d", &need[i]);
			need[i]--;
			findDependencies(need[i]);
		}

		int nodes = n;
		vector<int> res;

		while (nodes>0) {
			int node = -1;
			REP(i, n) {
				if (inDeg[i] == 0) {
					node = i;
					break;
				}
			}
			
			if (install[node] == 1) {
				res.push_back(node);
				install[node] = 0;
				
			}
			inDeg[node] = -1;
			REP(i, requiredBy[node].size()) {
				inDeg[requiredBy[node][i]]--;
			}

			nodes--;
		}

		printf("%d\n", res.size());
		REP(i, res.size()) {
			printf("%d ", res[i]+1);
		}
		printf("\n");


	}
	return 0;
}

//Solved