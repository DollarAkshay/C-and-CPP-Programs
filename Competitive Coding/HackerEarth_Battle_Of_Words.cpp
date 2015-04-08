/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/april-easy-challenge-15/algorithm/battle-of-words/

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

int a[26], b[26];
char s1[100005], s2[100005];

int main(){

	int t, n;

	scanf("%d", &t); getchar();
	REP(tc, t){
		gets(s1);
		gets(s2);
		//printf("S1 = %s\nS2 = %s\n", s1, s2);
		REP(i, 26)
			a[i] = b[i] = 0;
		int l1 = strlen(s1), l2 = strlen(s2);
		REP(i, l1)
			a[s1[i] - 'a']++;
		REP(i, l2)
			b[s2[i] - 'a']++;
		int c[26], n = 0, p = 0;

		REP(i, 26){
			c[i] = a[i] - b[i];
			if (c[i] > 0)p = 1;
			if (c[i] < 0)n = 1;
		}
		if (n^p == 0){
			puts("You draw some.");
		}
		else if (p == 1){
			puts("You win some.");
		}
		else
			puts("You lose some.");

	}
	return 0;
}

//Solved