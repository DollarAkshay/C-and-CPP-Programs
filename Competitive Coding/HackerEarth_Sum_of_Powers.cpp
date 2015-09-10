/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code_mania_80/algorithm/sum-of-powers-30/

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

bool ans[1000001];

void pre() {

	vector<int> powers;
	powers.pb(1);
	int i = 2;
	while (1) {
		int j = 2;
		while (1) {
			ll int res = pow(j, i);
			if (res>1000000)
				break;
			else
				powers.pb(res);
			j++;
		}
		if (j==2)
			break;
		i++;
	}
	REP(i, powers.size())
		FOR(j, i, powers.size()-1)
			if (powers[i]+powers[j]<1000000)
				ans[powers[i]+powers[j]] = 1;
}

int main(){

	pre();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		puts(ans[n]?"Yes":"No");
	}
	return 0;
}

//Solved