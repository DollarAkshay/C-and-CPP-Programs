/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/COOK62/problems/FRGTNLNG

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
#include <unordered_map>

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

int a[100000];


int main(){

	int t, n, k;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d %d", &n, &k);
		map<string, int> dict;
		vector<string> order;
		REP(i, n) {
			string s;
			cin>>s;
			getchar();
			dict[s] = 0;
			order.push_back(s);
		}

		REP(i, k) {
			int l;
			string s;
			scanf("%d", &l);
			getchar();
			REP(j, l) {
				cin>>s;
				if (dict.count(s))
					dict[s] = 1;
			}
		}
		REP(i, order.size()) {
			if (dict[order[i]]==1)
				printf("YES ");
			else
				printf("NO ");
		}
		printf("\n");
	}
	return 0;
}

//Solved