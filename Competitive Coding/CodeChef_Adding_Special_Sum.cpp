/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/COOK60/problems/COMB4SUM

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

int special(int a, int b, int c, int d){

	return abs(a+b-c-d) + abs(a-b+c-d) + abs(-a+b+c-d) + abs(a-b-c+d) + abs(-a+b-c+d) + abs(-a-b+c+d);

}

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		REP(i, 4)
			scanf("%d", &a[i]);
		ll int sum = special(a[0], a[1], a[2], a[3]);
		printf("%lld\n\n",sum);
	}
	sp;
	return 0;
}

//