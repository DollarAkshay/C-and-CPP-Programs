/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code_hunt_100-1/algorithm/count-carry-problem-1/

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

char s1[100], s2[100];

int add(int l1, int l2){

	int carry, c = 0;
	int maxl = max(l1, l2);
	for (int i = 0; i<maxl || carry>0; i++){
		int prod = s1[i] + s2[i];
		carry = (prod) / 10;
		if (carry)
			c++;
	}

	return c;
}

int main(){

	int t;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s %s", s1, s2);
		int l1 = strlen(s1), l2 = strlen(s2);
		REV(s1, l1);
		REV(s2, l2);
		REP(i, l1) s1[i] -= '0';
		REP(i, l2) s2[i] -= '0';
		int c = add(l1, l2);
		if (c>1)
			printf("%d carry operations\n", c);
		else if (c == 1)
			printf("%d carry operation\n", c);
		else
			printf("No carry operation\n");
	}
	return 0;
}

//