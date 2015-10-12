/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/586/problem/0

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

int main(){

	int n;
	deque<int> q;
	scanf("%d", &n);
	REP(i, n) {
		int x;
		scanf("%d", &x);
		q.push_back(x);
	}

	while (q.size()>0 && q.front()==0)
		q.pop_front();
	while (q.size()>0 && q.back()==0)
		q.pop_back();

	int sub=0, zero=0;

	REP(i, q.size()) {
		if (q[i]==0) {
			zero++;
		}
		else {
			if (zero>1) 
				sub += zero;
			zero = 0;
		}
	}
	printf("%d\n", q.size()-sub);
	return 0;
}

//Pretest passed