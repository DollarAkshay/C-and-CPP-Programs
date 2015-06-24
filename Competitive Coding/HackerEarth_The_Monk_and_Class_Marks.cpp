/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-monk-c-stl/algorithm/the-monk-and-class-marks/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

bool comp(const pair<int, string> &p1, const pair<int, string> &p2){

	if (p1.first != p2.first)
		return p1.first > p2.first;
	return p1.second < p2.second;
}

int main(){

	int n;
	vector<pair<int, string>> a;
	string s;
	int m;
	scanf("%d", &n);
	REP(i, n){
		cin >> s;
		scanf("%d", &m);
		a.push_back(make_pair(m, s));
	}
	int siz = a.size();

	sort(begin(a), begin(a) + siz, comp);

	REP(i, siz)
		printf("%s %d\n", a[i].second.c_str(), a[i].first);

	return 0;
}

//Solved