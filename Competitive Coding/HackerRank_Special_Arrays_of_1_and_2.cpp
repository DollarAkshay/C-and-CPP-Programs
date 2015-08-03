/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/101hack27/challenges/special-arrays-of-1-and-2

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

int a[50001];
ll int nCr[6];

void pre(){
	a[0] = 1;
	FOR(i, 1, 50000)
		a[i] = a[i-1]*2%MOD;
	nCr[0] = nCr[5] = 1;
	nCr[1] = nCr[4] = 5;
	nCr[2] = nCr[3] = 10;
}

int main(){

	pre();
	int t, n, s;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n, s);
		int two = s - 5;
		if (two<0 || two>5){
			printf("%d\n", a[n]);
		}
		else{
			int ans = (a[n] - (n-5)*(nCr[two]))%MOD;
			while (ans<0)
				ans += MOD;
			printf("%d\n", ans);
		}
	}
	return 0;
}

//