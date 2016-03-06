/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/megacodants/algorithm/margana-is-an-anagram/

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

	
	int t;

	scanf("%d", &t);
	REP(tc, t){
		char s1[1001], s2[1001];
		int f1[26], f2[26];
		int l1, l2;

		scanf("%s %s\n", s1, s2);

		MS0(f1);
		MS0(f2);
		l1 = strlen(s1);
		l2 = strlen(s2);

		REP(i, l1)
			f1[s1[i]-'a']++;

		REP(i, l2)
			f2[s2[i]-'a']++;

		int ana = 1;
		REP(i, 26) {
			if (f1[i] != f2[i]) {
				ana = 0;
				break;
			}
		}
		puts(ana?"Yes":"No");

	}
	sp;
	return 0;
}

//