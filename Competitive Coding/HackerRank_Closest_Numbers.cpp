/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/closest-numbers

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

int a[200000];

int main(){

	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	SORT(a, n);
	vector<int> ans;
	int min = 20000000;
	FOR(i, 1, n - 1){
		int diff = a[i] - a[i - 1];
		if (diff < min){
			min = diff;
			ans.clear();
			ans.push_back(a[i - 1]);
			ans.push_back(a[i]);
		}
		else if (diff == min){
			ans.push_back(a[i - 1]);
			ans.push_back(a[i]);
		}
	}
	int s = ans.size();
	REP(i, s) printf("%d ", ans[i]);

	return 0;
}

//Solved