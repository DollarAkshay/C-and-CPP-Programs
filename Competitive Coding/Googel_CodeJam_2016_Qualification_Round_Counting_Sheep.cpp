/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://code.google.com/codejam/contest/6254486/dashboard#s=p0

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

ll int last(int n) {

	if (n==0)
		return -1;

	ll int seen[10], sc = 0, i=1;

	MS0(seen);

	while (sc<10) {

		ll int x = n*i++;

		while (x>0) {
			if (!seen[x%10]) {
				seen[x%10] = 1;
				sc++;
			}
			x /= 10;
		}

		if (i>=1000) {
			return -1;
		}

	}

	return n*(i-1);

}


int main(){

	FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	int t, n;
	fscanf(in, "%d", &t);
	REP(tc, t){
		fscanf(in, "%d", &n);
		ll int res = last(n);
		if (res==-1)
			fprintf(out, "Case #%d: INSOMNIA\n", tc+1);
		else
			fprintf(out, "Case #%d: %lld\n", tc+1, res);
	}

	fclose(in);
	fclose(out);

	sp;
	return 0;
}

//Solved Small , and I think Large should have no problem :)