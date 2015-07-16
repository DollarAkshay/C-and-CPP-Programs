/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/ACODE/

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

char s[5001];
ll int DP[5001];

ll int ways(char s[]){

	ll int ans = 0;
	int len = strlen(s);

	if (DP[len])
		return DP[len];

	if (len==0)
		ans = 1;
	if (len>0 && s[0]!='0')
		ans += ways(s+1);
	if (len>1 && (s[0]=='1' || (s[0]=='2' && s[1]<='6')))
		ans += ways(s+2);

	DP[len] = ans;

	return DP[len];
}

int main(){

	while (scanf("%s", s)>0){
		if (s[0]=='0')
			break;
		MS0(DP);
		printf("%llu\n", ways(s));
	}
	sp;
	return 0;
}

//Solved