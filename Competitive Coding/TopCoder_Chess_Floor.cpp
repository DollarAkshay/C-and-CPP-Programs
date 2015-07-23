/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://arena.topcoder.com/#/u/coding/16512/13917/2

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

class ChessFloor{

public:
	int minimumChanges(vector <string> s){

		int f1[27], f2[27];
		int n = s.size();
		int c11 = -1, c12 = -1;
		int c21 = -1, c22 = -1;

		MS0(f1);
		MS0(f2);

		REP(i, n){
			FOR(j, i%2, n-1)
				f1[s[i][j++]-'a']++;
		}

		REP(i, n){
			FOR(j, 1-i%2, n-1)
				f2[s[i][j++]-'a']++;
		}

		int max1=-1, max2=-1;

		REP(i, 26){
			if (f1[i]>max1){
				c12 = c11;
				c11 = i;
				max2 = max1;
				max1 = f1[i];
			}
			else if (f1[i]>max2){
				c12 = i;
				max2 = f1[i];
			}
		}

		max1 = -1, max2 = -1;
		REP(i, 26){
			if (f2[i]>max1){
				c22 = c21;
				c21 = i;
				max2 = max1;
				max1 = f2[i];
			}
			else if (f2[i]>max2){
				c22 = i;
				max2 = f2[i];
			}
		}

		int c1=c11, c2=c21;

		if (c11==c21){
			if (f1[c11]>f2[c21]){
				c1 = c11;
				c2 = c22;
			}
			else{
				c2 = c21;
				c1 = c12;
			}
		}
		

		int ans;
		int c1sq = 0;
		REP(i, n)
			c1sq += i%2?(n-1)/2:(n+1)/2;
		
		ans = (c1sq-f1[c1]) + (n*n-c1sq-f2[c2]);
		return ans;
	}
};

//Pre Test Passed

