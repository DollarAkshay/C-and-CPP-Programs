/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-monk-heaps-and-priority-queues/algorithm/monk-and-iq/

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

deque<ll int> q[100005];
ll int stud[100005];

class Compare{
public:
	bool operator()(pair<ll int,ll int> n1, pair<ll int,ll int> n2) {
		return (n1.second>n2.second) || (n1.second==n2.second && n1.first>n2.first);
	}
};

int main(){

	ll int c, p, n, x;
	priority_queue<pair<ll int,ll int>, vector<pair<ll int,ll int>>, Compare> z;

	scanf("%lld%lld%lld", &c, &p, &n);
	REP(i, n){
		scanf("%lld", &x);
		stud[i]++;
		q[i].push_back(x);
		z.push(mp(i,x));
	}

	FOR(i,n,c-1)
		z.push(mp(i, 0));

	REP(i, p){
		scanf("%lld", &x);
		pair<ll int,ll int> block = z.top();
		z.pop();

		printf("%lld ", block.first+1);

		stud[block.first]++;
		q[block.first].push_back(x);
		while (q[block.first].size()>2)
			q[block.first].pop_front();

		ll int iqsum = 0;
		if (q[block.first].size()==2)
			iqsum = q[block.first][0]+q[block.first][1];
		else if (q[block.first].size()==1)
			iqsum = q[block.first][0];
		else
			iqsum = 0;
		z.push( mp(block.first, iqsum*stud[block.first]) );
	}

	return 0;
}

//Partially Solved