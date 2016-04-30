/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://code.google.com/codejam/contest/11254486/dashboard

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

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

bool found;
int len, valid_count;

char s[2005];
int valid[2005];
vector<int> ph;
vector<int> temp;

int findvalidchar(char c) {

	REP(i, len) {
		if (valid[i] && s[i]==c)
			return i;
	}

	return -1;

}

bool removestring(char sub[]) {

	int lsub = strlen(sub);
	vector<int> pos;

	REP(i, lsub) {
		int x = findvalidchar(sub[i]);
		if (x>=0) {
			valid[x] = false;
			valid_count--;
			pos.push_back(x);
		}
		else {
			REP(i, pos.size()) {
				valid[pos[i]] = true;
				valid_count++;
			}
			return false;
		}
	}

	return true;

}

void DFS() {

	if (valid_count==0) {
		found == true;
		REP(i, temp.size()) {
			ph.push_back(temp[i]);
		}
	}

	if (!found) {
		if (removestring("ONE")) {
			temp.push_back(1);
			DFS();
			temp.pop_back();
		}
		if (removestring("THREE")) {
			temp.push_back(3);
			DFS();
			temp.pop_back();
		}
		if (removestring("FIVE")) {
			temp.push_back(5);
			DFS();
			temp.pop_back();
		}
		if (removestring("SEVEN")) {
			temp.push_back(7);
			DFS();
			temp.pop_back();
		}
		if (removestring("NINE")) {
			temp.push_back(9);
			DFS();
			temp.pop_back();
		}
	}

}

int main(){

	int t;
	fscanf(in, "%d", &t);
	REP(tc, t){
		fscanf(in, "%s", s);

		valid_count = len = strlen(s);
		MS1(valid);
		ph.clear();
		found = false;

		while (removestring("ZERO"))
			ph.push_back(0);
		while (removestring("TWO"))
			ph.push_back(2);
		while (removestring("FOUR"))
			ph.push_back(4);;
		while (removestring("SIX"))
			ph.push_back(6);
		while (removestring("EIGHT"))
			ph.push_back(8);

		DFS();

		SORT(ph, ph.size());

		fprintf(out, "Case #%d: ", tc+1);
		REP(i, ph.size())
			fprintf(out, "%d", ph[i]);
		fprintf(out, "\n");
	}
	fclose(in);
	fclose(out);
	sp;
	return 0;
}

//Solved Small :) Large Pending 