/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/1483363301804d9f7c33bf6d832c6a908f3c507

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

struct point{
	int x, y;
};

char ascii[300][8100];

int main(){

	int w, h, len;
	char s[1000];
	scanf("%d%d", &w, &h);
	getchar();
	scanf("%[^\n]s", s);
	getchar();
	REP(i, h){
		scanf("%[^\n]s", ascii[i]);
		getchar();
	}

	len = strlen(s);
	REP(i, len){
		if (!isalpha(s[i]))
			s[i] = '[';
		else if (islower(s[i]))
			s[i] -= 32;
	}

	REP(i, h){
		REP(j, len){
			REP(k, w)
				printf("%c", ascii[i][(s[j] - 'A')*w + k]);
		}
		printf("\n");
	}

	return 0;
}

//Solved