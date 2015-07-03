/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codejunk/algorithm/beta-testing/

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

int a[100000];


bool comp(pair<int, string> l, pair<int, string> r){

	return (l.first > r.first);

}

int main(){

	int n;
	vector<pair<int, string>> m;
	scanf("%d", &n);
	REP(i, n){
		string c;
		cin >> c;
		int found = -1;
		REP(i, m.size()){
			if (m[i].second == c){
				found = i;
				break;
			}
		}
		if (found == -1)
			m.pb(make_pair(1, c));
		else
			m[found].first++;
	}
	sort(begin(m), end(m), comp);

	REP(i, m.size()){
		printf("%s %d\n", m[i].second.c_str(), m[i].first);
	}
	return 0;
}

//Solved