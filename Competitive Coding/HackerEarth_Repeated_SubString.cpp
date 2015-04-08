/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codezarena-v2/algorithm/repeated-substring/

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

	int t, n;
	char str[2001];
	scanf("%d", &t);
	REP(tc, t){
		int a[26];
		REP(i, 26)a[i] = 0;
		scanf("%s", str);
		int len = strlen(str),ans=0;

		REP(i, len){
			if (a[str[i] - 'a'] == 1){
				ans = 1;
				break;
			}
			a[str[i] - 'a']++;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}

//Solved