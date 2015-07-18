/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/BLCATS/

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


int main(){

	int n, k;
	string s;
	map<string, string> next;

	scanf("%d%d", &n, &k);
	getchar();
	REP(i, n){
		char c;
		scanf("%c", &c);
		s+=c;
	}

	REP(step, k){

		if (next.count(s)){
			s = next[s];
			continue;
		}

		string prev = s;
		REP(i, n){
			if (s[i] != s[(i+1)%n]){
				if (s[i]!='W' && s[(i+1)%n]!='W')
					s[i] = s[(i+1)%n] = 'W';
				else if (s[i]!='R' && s[(i+1)%n]!='R')
					s[i] = s[(i+1)%n] = 'R';
				else
					s[i] = s[(i+1)%n] = 'G';
			}
		}
		next[prev] = s;
	}

	printf("%s\n", s.c_str());
	sp;
	return 0;
}

//