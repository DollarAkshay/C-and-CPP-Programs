/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/M00PAIR/en/

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

vector<string> DP;

void pre(){

	DP.pb("0");
	DP.pb("0");
	FOR(k, 2, 999){
		string s;

		int car = 0;
		for (int i = 0; i<DP[k-1].size() || car>0; i++){
			int dig = i<DP[k-1].size()?DP[k-1][i]-'0':0;
			int pro = dig*2 + car;
			car = pro/10;
			int sum = pro%10;
			s += sum + '0';
		}

		s[0] += k%2?-1:1;

		REP(i, s.size()){
			if (s[i]=='/'){
				s[i] += 10;
				s[i+1]--;
			}
			else if (s[i]==':'){
				s[i] = 10;
				s[i+1]++;
			}
			else
				break;
		}

		DP.pb(s);
	}
}

int main(){

	pre();
	int n;
	while (scanf("%d", &n)>0){
		assert(n>=1 && n<=999);
		string s = DP[n];
		REV(s, s.size());
		printf("%s\n",s.c_str());
	}
	sp;
	return 0;
}

//Solved