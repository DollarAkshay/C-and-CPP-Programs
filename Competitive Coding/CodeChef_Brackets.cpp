/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/COOK52/problems/BRACKETS

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

int f(char s[]){
	int bal = 0, m = 0, len = strlen(s);
	REP(i, len){
		if (s[i] == '(')
			bal++;
		else if (s[i] == ')')
			bal--;
		m = max(bal, m);
	}
	return m;
}


int main(){

	int t;
	char str[100001];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", str);
		int b = f(str);
		REP(i, b) printf("(");
		REP(i, b) printf(")");
		printf("\n");
	}

	return 0;
}

//Solved