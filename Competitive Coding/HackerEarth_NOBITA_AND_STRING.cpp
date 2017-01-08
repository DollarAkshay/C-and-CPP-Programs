
//http://www.hackerearth.com/problem/algorithm/nobita-and-string-4/description/

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

char words[10000][1000];


int main(){

	int t,w;
	char str[100000];;
	scanf("%d", &t);
	REP(tc, t){
		getchar();
		gets(str);
		int len = strlen(str),j=0;
		w = 0;
		REP(i, len){
			if (str[i] == ' '){
				words[w++][j] = 0;
				j = 0;
			}
			else{
				words[w][j++] = str[i];
			}
		}
		while (w>=0)
			printf("%s ", words[w--]);
		printf("\n");
	}
	sp;
	return 0;
}

//Unsolved