/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/154201662ef1c71246c7d3c5e0c6462894a49cf

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
#define DB(s,x) fprintf(stderr,s,x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007


struct word{
	int score;
	char s[30];
};
int score[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

word dict[100001];

bool comp(word lhs, word rhs){

	return strcmp(lhs.s, rhs.s) > 0;
}



bool canMake(int x, char s[8]){

	int f1[26], f2[26];
	MS0(f1);
	MS0(f2);
	int l1 = strlen(dict[x].s), l2 = strlen(s);

	REP(i, l1)
		f1[dict[x].s[i]-'a']++;
	REP(i, l2)
		f2[s[i] - 'a']++;


	REP(i, 26){
		if (f1[i] > f2[i])
			return 0;
	}

	return 1;
}

int main(){

	int n;
	char words[8];
	scanf("%d", &n);
	REP(i, n){
		scanf("%s", dict[i].s);
		dict[i].score = 0;
		int l = strlen(dict[i].s);
		REP(j, l)
			dict[i].score += score[dict[i].s[j]-'a'];
	}
	scanf("%s", words);

	int score = 0;
	char ans[31];

	REP(i, n){
		if (canMake(i, words) && dict[i].score>score){
			score = dict[i].score;
			strcpy(ans, dict[i].s);
		}
	}
	printf("%s", ans);
	return 0;
}

//