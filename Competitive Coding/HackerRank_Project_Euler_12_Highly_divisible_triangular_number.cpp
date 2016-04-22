/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/projecteuler/challenges/euler012

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
#define MOD 1000000007'

ll int maxtri = 0;

vector<ll int> tri;
vector<ll int> diva;

void findDivCount(ll int n) {

	ll int divc = 0;
	int lim = sqrt(n);

	FOR(i, 1, lim) {
		if (n%i==0) {
			divc++;
			if (n/i>lim)
				divc++;
		}
	}

	tri.push_back(n);
	diva.push_back(divc);

}

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		while (diva.size()==0 || diva.back()<=n) {
			maxtri++;
			findDivCount(maxtri*(maxtri+1)/2);
		}

		int pos = upper_bound(diva.begin(), diva.end(), n) - diva.begin();
		printf("%lld\n", tri[pos]);
	}
	sp;
	return 0;
}

//