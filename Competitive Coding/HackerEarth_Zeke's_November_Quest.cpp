/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codification/algorithm/zekes-november-quest-1/

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

bool zeek(char *s1, char *s2,int len){

	int f1[26], f2[26];
	MS0(f1);
	MS0(f2);
	REP(i, len){
		f1[s1[i]-'a']++;
		f2[s2[i]-'a']++;
	}

	REP(i, 26){
		if (f1[i]!=f2[i])
			return false;
	}
	return true;
}

int main(){

	int t, n;
	char s[1001];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", s);
		int len = strlen(s);
		if (len%2)
			puts( zeek(s, s+(len+1)/2, (len-1)/2)?"YES":"NO");
		else
			puts(zeek(s, s+len/2, len/2)?"YES":"NO");
	}
	return 0;
}

//Solved