/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/COOK62/problems/STACKS

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

int a[1000000];

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		vector<int> top;
		REP(i, n) {
			scanf("%d", &a[i]);

			if (top.size()==0 || top[top.size()-1]<=a[i])
				top.push_back(a[i]);
			else {
				auto it = lower_bound(top.begin(), top.end(), a[i]+1);
				int index = it - top.begin();
				while (index>0 && top[index-1]>a[i]) {
					top[index] = top[index-1];
					index--;
				}
				top[index] = a[i];
			}
		}
		printf("%d ", top.size());
		REP(i, top.size())
			printf("%d ", top[i]);
		printf("\n");
	}
	sp;
	return 0;
}

//WOW Solved by Fulke :D