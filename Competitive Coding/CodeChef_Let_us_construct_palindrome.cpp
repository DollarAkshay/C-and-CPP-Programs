
//http://www.codechef.com/NOV14/problems/PRPALN

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

int f[26];

int chkPal(char s[]){

	int del = 0,i,j,len=strlen(s);
	for (i = 0, j = len - 1; i <= j; i++, j--){
		if (s[i] != s[j]){
			if (++del > 1)
				break;
			i--;
		}
	}
	if (del<2)
		return 1;

	del = 0;
	for (i = 0, j = len - 1; i <= j; i++, j--){
		if (s[i] != s[j]){
			if (++del > 1)
				return 0;
			j++;
		}
	}
	return 1;
}


int main(){

	char str[100001], cpy[100001],x;
	int t,pos;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%c%s", &x, str);
		puts(chkPal(str) ? "YES" : "NO");
	}
	sp;
	return 0;
}

//Solved 