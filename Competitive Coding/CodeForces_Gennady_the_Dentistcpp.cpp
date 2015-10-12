/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/586/problem/C

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

ll int p[4000], v[4000], d[4000];
int ran[4000];

int main(){

	int n;
	scanf("%d", &n);
	REP(i, n) 
		scanf("%I64d %I64d %I64d", &v[i], &d[i], &p[i]);


	vector<int> kids;
	ll int inQCry = 0;
	REP(i, n) {

		if (p[i]>=0) {
			kids.push_back(i+1);
			int vol = v[i];
			FOR(j, i+1, n-1) {
				if (!ran[j]) {
					p[j] -= vol;
					vol--;
				}
				if (vol<=0)
					break;
			}
		}

		FOR(j, i+1, n-1) {
			if (p[j]<0 && !ran[j]) {
				ran[j] = 1;
				FOR(k, j+1, n-1)
					p[k] -= d[j];
			}
		}
	}

	printf("%d\n", kids.size());
	REP(i, kids.size())
		printf("%d ", kids[i]);
	printf("\n");
	return 0;
}

//Solved