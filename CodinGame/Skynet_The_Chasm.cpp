/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/149122404f41d832b8880f5de44ceb3eb28ff66

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
#define DB(c,x) fprintf(stderr,"%s = %d\n",c,x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int main(){

	int r, g, l,s,x=0,a,b;
	scanf("%d%d%d", &r, &g, &l);
	r--;
	l += g+r;
	DB("l", l);
	while (1){
		scanf("%d%d", &s, &x);
		DB("x", x);
		DB("sum", s*(s - 1)/2);
		if (x<r && s <= g)
			printf("SPEED\n");
		else if (x<r && s >g+1)
			printf("SLOW\n");
		else if (x == r)
			printf("JUMP\n");
		else if (x>r && (x+s*(s+1)/2)>=l)
			printf("SLOW\n");
		else
			printf("WAIT\n");
	}
	return 0;
}

//Solved