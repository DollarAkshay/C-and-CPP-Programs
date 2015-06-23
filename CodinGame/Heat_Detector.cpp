/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/150214389545b0876dd7940a945319016665ae2

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


struct point{
	int x, y;
};

int main(){

	int w, h, turns;
	int xl, x, xh;
	int yl, y, yh;
	char s[2];
	scanf("%d%d%d%d%d", &w, &h, &turns, &x, &y);
	xl = 0;
	xh = w - 1;
	yl = 0;
	yh = h - 1;

	while (1){

		scanf("%s", s);
		if (s[0] == 'U')
			yh = y - 1;
		else if (s[0] == 'D')
			yl = y + 1;
		else if (s[0] == 'L')
			xh = x - 1;
		else if (s[0] == 'R')
			xl = x + 1;
		
		if (s[1] && s[1] == 'L')
			xh = x - 1;
		else if (s[1] && s[1] == 'R')
			xl = x + 1;

		x = (xl + xh) / 2;
		y = (yl + yh) / 2;
		printf("%d %d\n", x, y);
	}
	return 0;
}

//:D Solved