/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/substring-queries/description/

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



int main(){

	int t, q;
	char s[100001];

	scanf("%d", &t);

	REP(tc, t){

		scanf("%s", s);
		int len = strlen(s);
		scanf("%d", &q);

		REP(qc, q) {
			int res;
			char sub[100];
			scanf("%s", sub);

			int fsub[256];
			MS0(fsub);
			int lnesub = strlen(sub);
			REP(i, lensub) 
				fsub[sub[i]]++;
			


			FOR(i, 0, len-1) {
				int f[256];
				MS0(f);
				FOR(j, i, len-1) {

				}
			}
		}

	}
	sp;
	return 0;
}

//