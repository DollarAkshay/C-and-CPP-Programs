/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/593/problem/A

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

int f[26][26];

int main(){

	int n;
	char s[10000];
	scanf("%d", &n);
	REP(i, n) {

		scanf("%s", s);
		set<char> a;
		REP(i, 26) {
			if (strchr(s, (char)('a'+i))) 
				a.insert((char)('a'+i));
			if (a.size()>=3)
				break;
		}

		if (a.size()==2) {
			auto it = a.begin();
			char c1 = *it-'a';
			it++;
			char c2 = *it-'a';
			f[c1][c2] += strlen(s);
			f[c2][c1] += strlen(s);
		}
		else if (a.size()==1) {
			auto it = a.begin();
			char c1 = *it-'a';
			f[c1][c1] += strlen(s);
		}
	}

	int ans = 0;
	REP(i, 26) {
		FOR(j, i+1, 25)
			ans = max(ans, f[i][j] + f[j][j] + f[i][i]);
	}
	printf("%d\n", ans);
	return 0;
}

//PreTests Passed & Solved