/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

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
#define gc getchar_unlocked
struct Edge{ int v, w; };

int main(){

	int t;
	char s1[501], s2[501];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s%s", s1, s2);
		int l1 = strlen(s1), l2 = strlen(s2);
		int match = -1, pos = -1;
		FOR(i, 0, l2 - l1){
			int c = 0;
			REP(j, l1){
				if (s1[j] == s2[j + i])
					c++;
			}
			if (c > match){
				match = c;
				pos = i;
			}
		}
		printf("%d\n", l1 - match);
	}
	return 0;
}

//