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

int height(int s){

	v[s] = 1;
	int h=1, size = tree[s].size();
	REP(i, size){
		if (v[tree[s][i]]==0)
			h = max(h, 1+height(tree[s][i]));
	}
	v[s] = 0;
	return h;

}

int main(){

	int n, e;
	FILE *fp = fopen("testcase.txt", "r");
	scanf("%d", &e);
	n = e + 1;
	REP(i, e){
		int u, v;
		scanf("%d%d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	

	int fast = n;
	clock_t tim = clock();
	REP(i, n){
		if (tree[i].size()>1)
			fast = min(height(i),fast);
		if (i % 100 == 0){
			//system("cls");
			//printf("%.4f completed\n", (float)i * 100 / n);
		}
	}
	printf("%d\n", fast-1);
	tim = clock() - tim;
	//printf("Time taken = %f sec\n", (float)tim / CLOCKS_PER_SEC);
	return 0;
}

//