
//http://www.hackerearth.com/november-clash/algorithm/strings-awesomeness/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
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

int coun[26], he[26];
int ans[500001], sum[500001];


void init(){
	he['h' - 'a'] = 2;
	he['a' - 'a'] = 2;
	he['c' - 'a'] = 1;
	he['k' - 'a'] = 1;
	he['e' - 'a'] = 2;
	he['r' - 'a'] = 2;
	he['t' - 'a'] = 1;
}

int isAwesome(char *p){

	MS0(coun);
	int i = 0;
	while (i < 11){
		coun[*(p + i++) - 'a']++;
	}
	REP(i, 26){
		if (coun[i] ^ he[i])
			return 0;
	}
	return 1;

}


int main(){

	init();
	char str[500001], c, *p;
	int q, l, r, j = 0;
	while (c = getchar(), isalpha(c))
		str[j++] = tolower(c);
	str[j] = 0;

	p = str;
	while (p + 10 <= str + j - 1){
		ans[p - str] = isAwesome(p);
		if (p - str)
			sum[p - str] = ans[p - str] + sum[p - str - 1];
		else
			sum[p - str] = ans[p - str];
		p++;
	}

	scanf("%d", &q);
	REP(i, q){
		scanf("%d%d", &l, &r);
		l--; r--;
		if (r - l >= 10){
			printf("%d\n", sum[r - 10] - sum[l] + ans[l]);
		}
		else{
			puts("0");
		}
	}
	sp;
	return 0;
}
//Solved