/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/STPAR/

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


int main(){

	int n;
	while (scanf("%d", &n)>0){
		if (n==0)
			break;

		deque<int> q;
		stack<int> s;
		vector<int> a;

		REP(i, n){
			int x;
			scanf("%d", &x);
			q.push_back(x);
		}

		a.pb(0);
		int pos = 1;
		
		while (!q.empty() || !s.empty()){

			if ((s.size()>0 || q.empty()) && s.top()==a.back()+1 ){
				a.pb(s.top());
				s.pop();
			}
			else if (q.size()>0 && q.front()==a.back()+1){
				a.pb(q.front());
				q.pop_front();
			}
			else {
				if (s.empty() || q[0]<s.top()){
					s.push(q[0]);
					q.pop_front();
				}
				else{
					pos = 0;
					break;
				}
			}
		}

		puts(pos?"yes":"no");
	}
	return 0;
}

//Solved