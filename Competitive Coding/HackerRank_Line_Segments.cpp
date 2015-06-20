/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/epiccode/challenges/line-segments

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

struct line{
	int x1, x2;
	int covering, getincovered;
	int tot;
};

line a[100000];

bool compare(line lhs, line rhs){

	return lhs.tot < rhs.tot;
}

void check(int i, int j){

	if (a[i].x1 <= a[j].x1 && a[i].x2 >= a[j].x2){ //Cehck if i covers j
		a[i].covering++;
		a[j].getincovered++;
	}

	if (a[j].x1 <= a[i].x1 && a[j].x2 >= a[i].x2){ //Cehck if j covers i
		a[j].covering++;
		a[i].getincovered++;
	}

}


int checkcover(int x1, int x2, int y1, int y2){

	if (x1 <= y1 && x2 >= y2){ //Cehck if x covers y
		return 1;
	}

	if (y1 <= x1 && y2 >= x2){ //Cehck if y covers x
		return 1;
	}

	return 0;

}

int main(){

	int n;
	scanf("%d", &n);
	REP(i, n){
		scanf("%d%d", &a[i].x1, &a[i].x2);
		REP(j, i)
			check(i, j);
	}
	REP(i, n)
		a[i].tot = a[i].getincovered + a[i].covering;

	sort(begin(a), begin(a) + n, compare);

	vector<line> ans;
	REP(i, n){
		int size = ans.size(),add=1;
		REP(j, size){
			if (checkcover(a[i].x1, a[i].x2, ans[j].x1, ans[j].x2)){
				add = 0;
				break;
			}
		}
		if (add)
			ans.push_back(a[i]);
	}
	printf("%d\n", ans.size());

	return 0;
}

//