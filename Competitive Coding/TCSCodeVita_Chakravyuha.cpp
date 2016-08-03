/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.tcscodevita.com/CodevitaV5/problemstart.jsp

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

	int n;
	int m[100][100];
	vector<pii> power;
	scanf("%d", &n);

	power.push_back(mp(0, 0));

	int res = 1;

	FOR(r, 0, (n-1)/2) {

		FOR(k, r, n-1-r) {
			if (res%11==0)
				power.push_back(mp(r, k));
			m[r][k] = res++;
		}

		FOR(k, r+1, n-1-r-1) {
			if (res%11==0)
				power.push_back(mp(k, n-1-r));
			m[k][n-1-r] = res++;
		}

		FOR(k, r, n-1-r-1) {
			if (res%11==0)
				power.push_back(mp(n-1-r, n-1-k));
			m[n-1-r][n-1-k] = res++;
		}
		FOR(k, r, n-1-r-1) {
			if (res%11==0)
				power.push_back(mp(n-1-k, r));
			m[n-1-k][r] = res++;
		}

	}
	

	REP(i, n) {
		REP(j, n) 
			printf("%d\t", m[i][j]);
		printf("\n");
	}

	printf("Total Power Points: %d\n", power.size());
	REP(i, power.size())
		printf("(%d,%d)\n", power[i].first, power[i].second);

	return 0;
}

//