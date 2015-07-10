/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/thoughtworks-qa-hiring-challenge/problems/dd7f08d2b0e60e90dfc9214cd5aa0131/

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

	vector<string> s;

	s.pb("12:00:00"); //
	s.pb("00:00:00"); //
	s.pb("23:59:59"); //

	s.pb("-12:-30:-30"); //

	s.pb("99:99:99"); //

	s.pb("hh:mm:ss"); //

	s.pb("01,00:00"); //
	s.pb("01.00:00");
	s.pb("01;00:00");
	s.pb("01/00/00"); //

	s.pb("dd:00:00:ss"); //
	s.pb("Akshay....."); //
	s.pb("6000878877"); //

	s.pb(""); //


	printf("%d\n", s.size());
	REP(i, s.size())
		printf("%s\n", s[i].c_str());

	return 0;
}

//