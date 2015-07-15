/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/ONP/

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

int precedence(char c){
	if (c=='+')
		return 1;
	if (c=='-')
		return 2;
	if (c=='*')
		return 3;
	if (c=='/')
		return 4;
	if (c=='^')
		return 5;
	return 0;
}


int main(){

	int t;
	char e[401];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", e);
		stack<char> s;
		int len = strlen(e);

		REP(i, len){

			if (e[i]=='(')
				s.push(e[i]);

			else if (isalpha(e[i]))
				printf("%c", e[i]);

			else if (e[i]==')'){
				while (s.top()!='('){
					printf("%c", s.top());
					s.pop();
				}
				s.pop();
			}

			else{
				while (precedence(s.top())>precedence(e[i])){
					printf("%c", s.top());
					s.pop();
				}
				s.push(e[i]);
			}	

		}

		while (!s.empty()){
			printf("%c", s.top());
			s.pop();
		}

		printf("\n");
	}
	sp;
	return 0;
}

//Solved