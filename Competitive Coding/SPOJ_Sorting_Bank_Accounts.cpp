/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/SBANK/

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

int a[100000];

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		map<string, int> hash;
		REP(i, n){
			string s;
			char num[6][9];
			scanf("%2s %8s %4s %4s %4s %4s", num[0], num[1], num[2], num[3], num[4], num[5]);
			REP(i, 6){
				s += num[i];
				if (i!=5)
					s += ' ';
			}
			if (hash.count(s))
				hash[s]++;
			else
				hash[s] = 1;
		}
		for (auto it = hash.begin(); it!=hash.end(); it++)
			printf("%s %d\n", it->first.c_str(), it->second);
		printf("\n");
	}
	sp;
	return 0;
}

//