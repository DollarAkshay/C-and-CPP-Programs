/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/1521544efafcb4ea816c3d9c788484326738135

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
struct point{
	int x, y;
};

char dig[100][2000];
int w, h, n;

bool compareSymb(char s[100][100],ll int n){

	REP(i, h){
		REP(j, w){
			if (s[i][j] != dig[i][j + w*n])
				return 0;
		}
	}
	return 1;
}

int symbToDig(char s[100][100]){

	REP(i, 20){
		if (compareSymb(s, i))
			return i;
	}
	DB("(╯°□°)╯︵ ┻━┻\n", 0);
	return -1;

}

void printDig(ll int n){

	REP(i, h){
		REP(j, w)
			printf("%c",dig[i][j+n*w]);
			printf("\n");
	}

}

int main(){

	
	ll int a = 0, b = 0, res = 0;
	char sym[100][100],op;
	scanf("%d %d", &w, &h); getchar();
	REP(i, h)
		gets(dig[i]);
	scanf("%d", &n); getchar();
	FOR(i,1,n){
		gets(sym[(i - 1) % h]);
		if (i%h==0)
			a = a * 20 + symbToDig(sym);
	}
	scanf("%d", &n); getchar();
	FOR(i, 1, n){
		gets(sym[(i - 1) % h]);
		if (i % h == 0)
			b = b * 20 + symbToDig(sym);
	}
	scanf("%c", &op);
	switch (op){
	case '+':
		res = a + b;
		break;
	case '-':
		res = a - b;
		break;
	case '*':
		res = a*b;
		break;
	case  '/':
		res = a / b;
		break;
	}

	vector<int> base20;
	
	ll int p = 1;
	while (p < res)
		p *= 20;
	p /= 20;

	if (res==0)
		base20.push_back(0);
	while (p){
		ll int coef = res / p;
		base20.push_back(coef);
		res -= coef*p;
		p /= 20;
	}
	REP(i, base20.size())
		printDig(base20[i]);

	return 0;
}

//