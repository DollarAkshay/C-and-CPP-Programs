
//https://www.hackerrank.com/contests/codigo-mistreo/challenges/the-philosopher-box

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

int smu[36], non[36];
int check[26];


int checkNON(int x){

	REP(i, 26){
		if (non[i] == x)
			return 1;
	}
	return 0;
}

int checkBoth(int x){

	REP(i, 26){
		if (non[i] + smu[i] == x)
			return 1;
	}
	return 0;

}


int main(){

	int n, ans, cl = 0, nc = 0;
	char str[1000], x;
	scanf("%d", &n);
	REP(i, n){
		scanf("%c%s", &x, str);
		int len = strlen(str);
		MS0(check);
		if (strchr(str, '?')){
			nc++;
			REP(j, len){
				if (str[j] != '?' && !check[str[j] - 'a']){
					smu[str[j] - 'a']++;
					check[str[j] - 'a'] = 1;
				}
			}
		}
		else{
			cl++;
			REP(j, len){
				if (str[j] != '?' && !check[str[j] - 'a']){
					non[str[j] - 'a']++;
					check[str[j] - 'a'] = 1;
				}
			}
		}
	}
	if (checkNON(cl)){
		ans = 1;
		if (checkBoth(cl + nc))
			ans = 2;
	}
	else{
		ans = 0;
	}
	puts(ans ? ans == 2 ? "Yes" : "Maybe" : "No");

	return 0;
}

//Solved