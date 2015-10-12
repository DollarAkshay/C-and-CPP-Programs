/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/OCT15/problems/ADTRI

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

int p[5000001], ans[5000001];
vector<int> prime1;

void seiv() {

	MS1(p);
	p[0] = p[1] = 0;
	int lim = sqrt(5000001);
	for (int i = 2; i<=lim; i++) {
		if (p[i]) {
			for (ll int j = i*i; j<5000001; j += i)
				p[j] = 0;
		}
	}
	REP(i, 5000001) {
		if (p[i] && i%4==1)
			prime1.pb(i);
	}
}

void preCalc() {

	REP(i, prime1.size()) {
		for (int j = prime1[i]; j<5000001; j += prime1[i])
			ans[j] = 1;
	}

}

int main(){

	seiv();
	preCalc();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		puts(ans[n]?"YES":"NO");
	}
	sp;
	return 0;
}

//Solved