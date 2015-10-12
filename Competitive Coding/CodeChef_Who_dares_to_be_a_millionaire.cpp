/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/OCT15/problems/WDTBAM

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

int a[100000];

int noofMatchingChars(char *s1, char *s2, int len) {
	
	int res = 0;
	REP(i, len)
		if (s1[i]==s2[i])
			res++;
	return res;
}

int main(){

	int t, n;
	char s1[10001], s2[10001];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		scanf("%s", s1);
		scanf("%s", s2);
		REP(i, n+1)
			scanf("%d", &a[i]);
		int correct = noofMatchingChars(s1, s2, n);
		int winnings = 0;
		if (correct<n) {
			FOR(i, 0, correct)
				winnings = max(a[i], winnings);
		}
		else {
			winnings = a[n];
		}
		printf("%d\n", winnings);
	}
	sp;
	return 0;
}

//Solved