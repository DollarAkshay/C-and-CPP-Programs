/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/LTIME25/problems/CHEFSTLT

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int main(){

	int t, n;
	char s1[101], s2[101];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", s1);
		scanf("%s", s2);
		int min=0, max=0;
		int len = strlen(s1);
		REP(i, len){
			if (s1[i] == '?' || s2[i] == '?')
				max++;
			else if (s1[i] != s2[i]){
				min++;
				max++;
			}
		}
		printf("%d %d\n", min, max);
	}

	return 0;
}

//