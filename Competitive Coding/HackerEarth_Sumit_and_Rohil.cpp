/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/september-easy-15/algorithm/sumit-and-rohil/

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

struct group {
	char f, l;
	int freq[256];
	group(char s[]) {
		int len = strlen(s);
		f = s[0];
		l = s[len-1];
		MS0(freq);
		REP(i, l)
			freq[s[i]]++;
	}
	bool operator==(const group& rhs) const {
		if (f==rhs.f && l==rhs.l) {
			REP(i, 256) {
				if (freq[i] != rhs.freq[i])
					return false;
			}
			return true;
		}
		else
			return false;
	}
};

int main() {

	char s[1001];
	int t;
	vector<group> hash;
	scanf("%d", &t);
	REP(tc, t) {
		scanf("%s", s);
		group g = group(s);
		int found = 0;
		REP(i, hash.size()) {
			if (g == hash[i]) {
				found = 1;
				break;
			}
		}
		if (!found)
			hash.pb(g);
	}
	printf("%d", hash.size());
	return 0;
}

//Solved