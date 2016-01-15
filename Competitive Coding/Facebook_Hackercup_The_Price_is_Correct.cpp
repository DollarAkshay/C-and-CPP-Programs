/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.facebook.com/hackercup/problem/881509321917182/

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


ll int a[100005], sum[100005];

int bsearch_lt(int key, int lo, int hi, ll int off) {

	int mid, res = -1;
	while (lo<=hi) {
		mid = (lo+hi)/2;
		if (sum[mid]-off<=key) {
			res = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return res;
}


int main() {

	ll int t, n, p;
	FILE *fin = fopen("C:\\Users\\Akshay L Aradhya\\Downloads\\data2.txt", "r");
	FILE *fout = fopen("C:\\Users\\Akshay L Aradhya\\Downloads\\result2.txt", "w");

	fscanf(fin, "%lld", &t);
	REP(tc, t) {
		fscanf(fin, "%lld %lld", &n, &p);
		REP(i, n) {
			fscanf(fin, "%lld", &a[i]);
			sum[i+1] = i?sum[i]+a[i]:a[i];
		}
		ll int res = 0;
		FOR(i, 0, n-1) {
			FOR(j, i, n-1) {
				if (sum[j]-sum[i-1]<=p)
					res++;
			}
		}
		fprintf(fout, "Case #%d: %lld\n", tc+1, res);

	}
	fclose(fin);
	fclose(fout);
	return 0;
}

//Solved I think