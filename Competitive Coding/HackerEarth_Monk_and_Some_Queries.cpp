/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-monk-heaps-and-priority-queues/algorithm/monk-and-some-queries/

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

int valid[100001];

int main(){

	int  n, t, x;
	priority_queue<int> qmax;
	priority_queue<int, vector<int>, greater<int>> qmin;
	scanf("%d", &n);
	REP(i, n){
		scanf("%d", &t);
		if (t==1){
			scanf("%d", &x);
			qmax.push(x);
			qmin.push(x);
			valid[x]++;
		}
		else if (t==2){
			scanf("%d", &x);
			if (valid[x]>=1)
				valid[x]--;
			else
				printf("-1\n");
		}
		else if (t==3){
			while (valid[qmax.top()]==0 && qmax.size())
				qmax.pop();
			if (qmax.size())
				printf("%d\n", qmax.top());
			else
				printf("-1\n");
		}
		else if (t==4){
			while (valid[qmin.top()]==0 && qmin.size())
				qmin.pop();
			if (qmin.size())
				printf("%d\n", qmin.top());
			else
				printf("-1\n");
		}
		else
			assert(1==0);
	}

	return 0;
}

//Solved