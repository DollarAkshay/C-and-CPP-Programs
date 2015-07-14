/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/15086967aa86622a9f16367bfcfd1ad52cc3d5a

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <list>
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
#define mp(a,b) make_pair(a,b)
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__);
#define MS(x,n) memset(x,n,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007


vector<string> s;
vector<int> order;

int overlap(string s1, string s2){

	int max = 0;
	FOR(i, 1, min(s1.size(), s2.size()) ){
		if (strncmp(s1.c_str()+s1.size()-i, s2.c_str(), i)==0)
			max = i;
	}
	return max;
}


int main(){

	int n;
	s.pb("");
	scanf("%d", &n);
	REP(i, n){
		char ts[11];
		scanf("%s", ts);
		s.pb(ts);
	}
	//sort(s.begin(), s.end());

	order.pb(0);
	order.pb(1);
	order.pb(0);

	FOR(i, 2, n){

		int isSub = 0;
		FOR(j, 1, order.size()-2){
			if (strstr(s[order[j]].c_str(),s[i].c_str())){
				isSub = 1;
				break;
			}
		}
		if (isSub)
			continue;

		int max = -1, pos = -1;
		FOR(j, 1, order.size()-1){
			int r = overlap(s[i], s[order[j]]);
			int l = overlap(s[order[j-1]], s[i]);
			int o = 0;
			REP(k,j-1)
				o += overlap(s[order[k]], s[order[k+1]]);

			FOR(k, j, order.size()-2)
				o += overlap(s[order[k]], s[order[k+1]]);

			if (l+r+o>max){
				max = l+r+o;
				pos = j;
			}
		}
		auto it = order.begin();
		while (pos--)
			it++;
		order.insert(it, i);
	}

	string res = s[order[1]];

	FOR(i, 2, order.size()-2){
		if (strstr(res.c_str(), s[order[i]].c_str()))
			continue;
		int l = overlap(s[order[i]], res);
		int r = overlap(res, s[order[i]]);

		if (l>r){
			string t = res;
			res = s[order[i]];
			res.insert(res.end(), t.begin()+l, t.end());
		}
		else{
			res.insert(res.end(), s[order[i]].begin()+r, s[order[i]].end());
		}
	}
	DB("Res = %s\n", res.c_str());
	printf("%d", res.size());
	return 0;
}

//Solved