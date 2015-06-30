/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/1501979c5826b8fce972ef1585667dccb9b288a

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
struct point{
	int x, y;
};

vector<int> tree[150000];

int v[150000];
int n, e;

int topo(){

	int erased = 0,time = 0;
	vector<int> leaf;
	while (erased < e){

		REP(i, n){
			if (tree[i].size() == 1){
				leaf.push_back(i);
				erased++;
			}
		}

		REP(i, leaf.size()){
			int x;
			if (tree[leaf[i]].size() >= 1){
				REP(j, tree[tree[leaf[i]][0]].size()){
					if (tree[tree[leaf[i]][0]][j] == leaf[i]){
						x = j;
						break;
					}
				}
				tree[tree[leaf[i]][0]].erase(tree[tree[leaf[i]][0]].begin() + x);
				tree[leaf[i]].clear();
			}
		}
		leaf.clear();
		time++;
	}
	return time;
}

int main(){

	
	scanf("%d", &e);
	n = e + 1;
	REP(i, e){
		int u, v;
		scanf("%d%d", &u, &v);
		n = max(u + 1, n);
		n = max(v + 1, n);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	printf("%d", topo());
	return 0;
}

//