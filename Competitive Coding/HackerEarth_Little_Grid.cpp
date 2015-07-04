/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codex-6-0/algorithm/dummy-1-1/

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
#define mp(x) make_pair(x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int main(){

	char s[1000000]="";
	char t[1000000];

	REP(i, 7){
		scanf("%s", t);
		strcat(s, t);
	}

	int n = strlen(s);
	int x = 0;
	REP(i, n)
		if (s[i] == '1')
			x++;
	double mean = (double)x / n;
	double sig = 0;
	REP(i, n)
		sig += ((s[i] - '0') - mean)*((s[i] - '0') - mean);
	sig /= n;
	sig = sqrt(sig);
	printf("%.4lf\n", round(sig * 10000) / 10000);

	return 0;
}

//