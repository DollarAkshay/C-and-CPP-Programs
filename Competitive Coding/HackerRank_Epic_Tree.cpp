/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/epiccode/challenges/epic-tree

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


vector<int> tree[100000];
int n, subsum, sum[100000], parent[100000];

void dfs(int s){

	int size = tree[s].size();
	REP(i, size){
		if (parent[tree[s][i]] == 0){
			parent[tree[s][i]] = s;
			dfs(tree[s][i]);
		}
	}
}

void updatesubtree(int s, int t){

	sum[s] = (sum[s] + t) % 10009;
	int size = tree[s].size();
	REP(i, size){
		if (parent[s] != tree[s][i])
			updatesubtree(tree[s][i], t);
	}

}


void findsumsubtree(int s){

	subsum = (subsum + sum[s]) % 10009;
	int size = tree[s].size();
	REP(i, size){
		if (parent[s] != tree[s][i])
			findsumsubtree(tree[s][i]);
	}

}

int main(){

	int m;
	scanf("%d", &n);
	REP(i, n - 1){
		int u, v;
		scanf("%d%d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	parent[1] = -1;
	dfs(1);

	scanf("%d", &m);

	int q, a, b, t;
	REP(i, m){
		scanf("%d", &q);
		if (q == 1){
			scanf("%d%d%d", &a, &b, &t);
			while (a != b){
				if (a > b){
					updatesubtree(a, t);
					a = parent[a];
				}
				else {
					updatesubtree(b, t);
					b = parent[b];
				}
			}
			updatesubtree(a, t);
		}
		else{
			scanf("%d", &a);
			subsum = 0;
			findsumsubtree(a);
			printf("%d\n", subsum % 10009);
		}
	}

	return 0;
}

//Partially Solved ~ TLE