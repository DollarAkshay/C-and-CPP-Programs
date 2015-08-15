/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/codeagon/challenges/gohan-and-blocks

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

int a[100000], len;
map<string, int> res;

void gen(stack<char> s, string left, string right){

	if (left.size()==len){
		if (res.count(left))
			res[left]++;
		else
			res[left] = 1;
		return;
	}

	stack<char> stcpy = s;
	string lcpy = left, rcpy = right;

	if (stcpy.size()){
		lcpy += stcpy.top();
		stcpy.pop();
		gen(stcpy, lcpy, rcpy);
	}
	if (right!=""){
		stcpy = s;
		lcpy = left; rcpy = right;
		stcpy.push(right[0]);
		rcpy.erase(0, 1);
		gen(stcpy, lcpy, rcpy);
	}

}

int main(){

	char s[11];
	scanf("%s", s);
	len = strlen(s);
	stack<char> empty;
	string l = "", r = s;
	gen(empty, l, r);
	printf("%d %d", res[s], res.size());
	return 0;
}

//Solved