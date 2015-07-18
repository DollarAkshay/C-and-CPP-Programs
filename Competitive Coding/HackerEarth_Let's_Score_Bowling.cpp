/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/CodeTreat1/algorithm/lets-score-bowling/

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

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int a[100000];

int main(){

	int t, a, b, c;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d%d", &a, &b, &c);
		int score = 0;
		if (a==9){
			score += 10;
			printf("%d\n", score);
			continue;
		}
		else if (a<9 && a>6)
			score += 2;
		else if (a<7 && a>0)
			score += 1;

		if (b==9){
			score += 7;
			printf("%d\n", score);
			continue;
		}
		else if (b<9 && b>6)
			score += 2;
		else if (b<7 && b>0)
			score += 1;

		if (c==9){
			score += 4;
			printf("%d\n", score);
			continue;
		}
		else
			printf("0\n");

	}
	return 0;
}

//Solved