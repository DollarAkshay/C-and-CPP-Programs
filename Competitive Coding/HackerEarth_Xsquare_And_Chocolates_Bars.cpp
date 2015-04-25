/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/awesome-april-15/algorithm/xsquare-and-chocolates-bars-2/

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
	char s[1000001];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", s);
		int box = 0, max = 0, len = strlen(s);
		REP(i, len - 2){
			if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]){
				i -= 3 * box;
				max = box > max ? box : max;
				box = 0;
			}
			else{
				box++;
				i += 2;
			}
		}
		max = box > max ? box : max;
		printf("%d\n", len - max * 3);
	}
	return 0;
}

//Solved