/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

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
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int n;

int v[100000];
set<vector<int>> all;

void DFS(vector<int> a) {

	if (a.size()==n) {
		all.insert(a);
		return;
	}

	FOR(i, 1, n) {
		if (v[i]==0) {
			a.push_back(i);
			v[i] = 1;
			DFS(a);
			a.pop_back();
			v[i] = 0;
		}
	}

}

set<vector<int>> subsetHavingEdge(set<vector<int>> s, int u, int v) {

	set<vector<int>> sub;



}

void printSet(set<vector<int>> s) {

	int k = 0;
	for (auto it = s.begin(); it!=s.end(); it++) {
		REP(i, n)
			printf("%d ", it->at(i));
		if (++k%6==0)
			printf("\n");
		else
			printf("\t");
	}

}

int main(){

	scanf("%d", &n);
	vector<int> a;
	DFS(a);
	printSet(all);

	sp;
	return 0;
}

//