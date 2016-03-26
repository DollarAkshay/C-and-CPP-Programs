/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/LTIME34/problems/ABABAABA

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

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		char s[5001];
		scanf("%s", s);
		int a = 0, b = 0, len = strlen(s);
		REP(i, len) {
			if (s[i]=='A')
				a++;
			else
				b++;
		}

		int conseq = -1;
		REP(i, len-1) {
			if (len>=3 && i==0 && s[i]==s[i+1] && s[i+1]!=s[i+2]) {
				conseq = i;
				break;
			}
			else if(len>=3 && i==len-2 && s[i]==s[i+1] && s[i]!=s[i-1]){
				conseq = i;
				break;
			}
			else if (len>=4 && s[i-1]!=s[i] && s[i]==s[i+1] && s[i+1]!=s[i+2]) {
				conseq = i;
				break;
			}
		}

		if (a==2)
			puts("A");
		else if (b==2)
			puts("B");
		else if (conseq!=-1) {
			REP(i, len) {
				if(i!=conseq)
					printf("%c", s[i]);
			}
			printf("\n");
		}
		else
			puts("-1");
	}
	sp;
	return 0;
}

//Solved