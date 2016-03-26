/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/MARCH16/problems/CHEFSPL

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
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

int mistakes(string s1, string s2) {

	int l = s1.length();
	int mist = 0;

	for (int i = 0, j = 0; i<l && j<l;) {
		if (s1[i] == s2[j]) {
			i++;
			j++;
		}
		else {
			if (++mist>1)
				return mist;
			i++;
		}
	}
	return mist;

}

bool check(string s) {

	int n = s.size();
	int l = (n+1)/2;

	if (n==1)
		return false;

	if (n%2==1) {

		string s1, s2;

		s1 = s.substr(0, l);
		s2 = s.substr(l, n/2);
		int mist1 = mistakes(s1, s2);

		s1 = s.substr(0, l-1);
		s2 = s.substr(l-1, n/2+1);
		int mist2 = mistakes(s2, s1);

		if (mist1<=1 || mist2<=1) 
			return true;
		else {
			return false;
		}

	}
	else {
		REP(i, s.size()/2) {
			if (s[i] != s[i + s.size()/2])
				return false;
		}
		return true;
	}

}


int main(){


	int t;
	cin>>t;

	REP(tc, t){
		string s;
		cin>>s;
		printf("%s\n",check(s)?"YES":"NO");
	}

	sp;
	return 0;
}

//Solved