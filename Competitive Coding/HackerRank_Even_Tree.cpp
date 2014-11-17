//https://www.hackerrank.com/challenges/even-tree

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

vector <int> tree[100];

int treeSize(int n){

	queue<int> q;
	int i, c = 0;
	q.push(n);
	while (!q.empty()){
		i = q.front();
		q.pop();
		c++;
		for (int j = 0; j < tree[i].size(); j++){
			q.push(tree[i][j]);
		}
	}
	return c;
}


int main(){

	int n, m, a, b;
	scanf("%d%d", &n, &m);
	REP(i, m){
		scanf("%d%d", &a, &b);
		a--; b--;
		tree[b].push_back(a);
	}
	int c = 0;
	for (int i = 0; i <n; i++){
		if (treeSize(i) % 2 == 0)
			c++;
	}
	if (n % 2 == 0)
		c--;
	cout << c;

	return 0;
}

//Solved