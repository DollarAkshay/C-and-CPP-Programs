/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://code.google.com/codejam/contest/6254486/dashboard#s=p1

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

string flip(string s, int k) {

	string res = s;

	REP(i, k) 
		res[i] = s[k-i-1]=='+'?'-':'+';

	return res;

}

int solve(string s, int j) {

	if (j<0)
		return 0;

	int flips = 0;

	int k = 0;
	while (s[k]=='+') {
		s[k] = '-';
		flips = 1;
		k++;
	}

	s = flip(s, j+1);
	flips++;

	return flips + solve(s, s.find_last_of('-'));

}

int main(){

	FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	int t, n;
	fscanf(in, "%d", &t);
	fgetc(in);
	REP(tc, t){
		char str[1000];
		fscanf(in, "%[^\n]", str);
		fgetc(in);
		string s = str;
		int res = solve(s, s.find_last_of('-'));
		fprintf(out, "Case #%d: %d\n", tc+1, res);
	}
	fclose(in);
	fclose(out);
	sp;
	return 0;
}

//Solved the Small Testcases. Hopefully the Large one is right too :)