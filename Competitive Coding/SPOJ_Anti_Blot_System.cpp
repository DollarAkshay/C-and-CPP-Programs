/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/PALIN/

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

bool isBlot(char s[]){

	int len = strlen(s);
	REP(i, len){
		if (!isdigit(s[i]))
			return true;
	}
	return false;
}

int intToString(char s[]){

	int len = strlen(s), res = 0;

	REP(i, len)
		res = res*10 + s[i]-'0';
	
	return res;
}

int main(){

	int t;
	char op1[50], op2[50], op3[50];
	scanf("%d", &t);
	REP(tc, t){
		getchar();
		scanf("%s + %s = %s",op1,op2,op3);
		int a, b, res;

		if (isBlot(op3)){
			a = intToString(op1);
			b = intToString(op2);
			res = a+b;
		}
		else if (isBlot(op2)){
			a = intToString(op1);
			res = intToString(op3);
			b = res - a;
		}
		else if (isBlot(op1)){
			b = intToString(op2);
			res = intToString(op3);
			a = res - b;
		}
		printf("%d + %d = %d\n", a, b, res);
	}
	sp;
	return 0;
}

//Solved