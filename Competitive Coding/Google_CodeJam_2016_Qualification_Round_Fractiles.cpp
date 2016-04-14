/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://code.google.com/codejam/contest/6254486/dashboard#s=p3

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

	FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	int t, n;
	fscanf(in, "%d", &t);
	REP(tc, t){
		int k, c, s;
		fscanf(in, "%d %d %d", &k, &c, &s);
		ll int kc = pow(k, c-1);

		if (s>=k) {
			fprintf(out, "Case #%d:", tc+1);

			REP(i, k)
				fprintf(out, " %lld", kc*i + 1);
			fprintf(out, "\n");
		}
		else {
			fprintf(out, "Case #%d: IMPOSSIBLE\n", tc+1);
		}
	}
	fclose(in);
	fclose(out);
	sp;
	return 0;
}

//Solved the Small Testcases