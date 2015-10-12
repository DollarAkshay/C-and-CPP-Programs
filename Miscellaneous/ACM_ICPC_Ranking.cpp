/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

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
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

vector<pair<int, string>> ranklist;
vector<string> selected;

bool compare(pair<string, int> lhs, pair<string, int> rhs) {
	return (lhs.second>rhs.second) || (lhs.second==rhs.second && lhs.first<rhs.first);
}

int main(){

	
	char name[1000];
	int rank, longestName = 0;
	FILE *f = fopen("ICPC.txt", "r");

	if (!f)
		printf("FILE ERROR\n");

	while ( fscanf(f, "%d %[^\n]", &rank, name)>0 ) {
		string str(name);
		longestName = max((ll int)longestName, (ll int)str.size());
		ranklist.push_back(mp(rank, str));
	}
	printf("DONE READING\n");

	map<string, int> college;
	REP(i, ranklist.size()) {
		if (college.count(ranklist[i].second)==0) {
			selected.push_back(ranklist[i].second);
			college[ranklist[i].second]=1;
		}
		else {
			college[ranklist[i].second]++;
		}
	}
	printf("DONE\n");

	vector<pair<string, int>> CollegeTeamCount(college.begin(), college.end());
	sort(CollegeTeamCount.begin(), CollegeTeamCount.end(), compare);

	printf("Colleges Rank: \n");
	REP(i, selected.size()) {
		printf("%3d %-s \n", i+1, selected[i].c_str());
	}




	sp;

	return 0;
}

//