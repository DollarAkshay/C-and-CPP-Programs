/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codestellar-3/algorithm/v-number/

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

int ispali(int n){

	int rev = 0, orig = n;
	while (n){
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	if (rev == orig)
		return 1;
	else
		return 0;
}


int main(){

	int t;
	char s[10000];
	scanf("%d", &t);
	getchar();
	REP(tc, t){
		scanf("%s", s);
		int len = strlen(s);
		int ls = 0, rs = 0;
		for (int i = 0, j = len - 1; i<j; i++, j--){
			ls += s[i] - '0';
			rs += s[j] - '0';
		}
		puts(ls == rs ? "YES" : "NO");
	}
	return 0;
}

//Solved