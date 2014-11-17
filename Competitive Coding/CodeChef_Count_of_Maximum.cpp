
//http://www.codechef.com/CDSM2014/problems/CHFMAX

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

int f[26];


int main(){

	int t,max,j;
	char str[1001];
	scanf("%d", &t);
	REP(tc, t){
		j = max = 0;
		MS0(f);
		scanf("%s", str);
		int len = strlen(str);
		REP(i, len) 
			f[str[i] - 'a']++;
		REP(i, 26){
			if (f[i] > max){
				max = f[i];
				j = i;
			}
		}
		REP(i, len){
			if (str[i] == 'a' + j)
				str[i] = '?';
		}
		cout << str << endl;
	}
	return 0;
}

// Solved