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

void trim(char s[]){

	int len = strlen(s), j;
	FORD(i, len - 1, 0){
		if (s[i] == ' ')
			s[i] = 0;
		else
			break;
	}
	len = strlen(s);
	REP(i, len){
		if (s[i] != ' '){
			j = i;
			break;
		}
	}

	REP(i, len)
		s[i] = s[i + j];
}



int main(){

	char s[1000][1001];
	int n = 0, mlen = 0;
	while (n<7 && gets(s[n])>0){

		trim(s[n]);

		int len = strlen(s[n]);
		mlen = max(len, mlen);
		n++;
	}

	REP(i, mlen + 2)
		printf("*");
	printf("\n");

	REP(i, n){
		printf("*");
		int spac = mlen - strlen(s[i]);
		int l, r;
		if (spac % 2){
			l = (spac + 1) / 2;
			r = spac / 2;
		}
		else
			l = r = spac / 2;
		REP(i, l)
			printf(" ");
		printf("%s", s[i]);
		REP(i, r)
			printf(" ");
		printf("*\n");
	}

	REP(i, mlen + 2)
		printf("*");
	sp;
	return 0;
}

//