/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/JULY15/problems/CHCUBE

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
#define mp(x) make_pair(x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int a[6];

int colorToNumber(char s[10]){

	if (s[0] == 'r')
		return 2;
	else if (s[0] == 'g')
		return 3;
	else if (s[0] == 'y')
		return 4;
	else if (s[0] == 'o')
		return 5;
	else if (s[0] == 'b'){
		if (s[2] == 'a')
			return 0;
		else
			return 1;
	}
}

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		REP(i, 6){
			char str[10];
			scanf("%s", str);
			a[i] = colorToNumber(str);
		}
		int found=0;
		FOR(i, 0, 1){
			FOR(j, 2, 3){
				FOR(k, 4, 5){
					if (a[i] == a[j] && a[j] == a[k]){
						found = 1;
						i = j = k = 6;
					}
				}
			}
		}
		puts(found?"YES":"NO");
	}
	return 0;
}

//Solved