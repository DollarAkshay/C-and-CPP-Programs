/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/OCT15/problems/PERSHFTS

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

struct seq {
	vector<int> a;
	seq(vector<int> x) {
		a = x;
	}
	void shift(int i, int k) {
		int t = a[i+k-1];
		a.erase(a.begin()+i+k-1);
		a.insert(a.begin()+i, t);
	}
	bool operator <(const seq rhs) const {
		REP(i, a.size()) {
			if (a[i]==rhs.a[i])
				continue;
			else
				return a[i]<rhs.a[i];
		}
		return false;
	}
	bool operator ==(const seq rhs) const {
		REP(i, a.size()) {
			if (a[i]!=rhs.a[i])
				return false;
		}
		return true;
	}
};

vector<int> p, q;

int BFS(int n, int k) {

	seq s = seq(p);
	seq qs = seq(q);
	queue<seq> qu;
	set<seq> perm;

	qu.push(s);
	perm.insert(s);

	while (!qu.empty()) {
		seq a = qu.front();
		qu.pop();
		REP(i, n-k+1) {
			seq newSeq = a;
			newSeq.shift(i, k);
			if (perm.count(newSeq)==0) {
				perm.insert(newSeq);
				qu.push(newSeq);
			}
		}
	}

	int ki = 0;
	for (auto i = perm.begin(); i!=perm.end(); i++,ki++) {
		if (*i==qs)
			return ki+1;
	}
	return -1;
}

int main(){

	int t, n, k;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &k);
		q.clear();
		p.clear();
		REP(i, n) {
			int x;
			scanf("%d", &x);
			p.pb(x);
		}
		REP(i, n) {
			int x;
			scanf("%d", &x);
			q.pb(x);
		}
		printf("%d\n", BFS(n, k));
	}
	sp;
	return 0;
}

//Partially Solved ~ TLE