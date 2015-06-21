/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/COOK59/problems/ANKNIM2

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

int ans[100001];
vector<pair<int, int>> cumxor;

void calc(int a, int b){
	FOR(i, a, b){
		FOR(j, i + 1, b)
			ans[abs(cumxor[i].second - cumxor[j].second)]++;
	}
}

int main(){

	int t, n;
	int a[100000];
	FILE *fp = fopen("testcase.txt", "r");
	fscanf(fp,"%d", &t);
	REP(tc, t){
		fscanf(fp,"%d", &n);
		MS0(ans);
		cumxor.clear();
		cumxor.push_back(make_pair(0,0));
		REP(i, n){
			fscanf(fp,"%d", &a[i]);
			cumxor.push_back(make_pair( cumxor[i].first^a[i], i+1) );
		}
		SORT(cumxor, n + 1);

		REP(i, n){
			int j = i;
			while (j+1 <=n && cumxor[j + 1].first == cumxor[i].first)
				j++;
			if (j > i)
				calc(i, j);
			i = j;
		}

		FOR(i,1,n)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}

//