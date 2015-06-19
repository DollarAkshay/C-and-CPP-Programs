/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/14905944f8d80ca4f01c50b9368b922e3157fe3

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

int main(){

	int x, y;
	int m[10],hig,pos;
	while (1){
		scanf("%d%d",&x,&y);
		pos = -1;
		hig = -1;
		REP(i, 8){
			scanf("%d", &m[i]);
			if (m[i] > hig){
				hig = m[i];
				pos = i;
			}
		}
		puts(x^pos ? "HOLD" : "FIRE");
	}
	return 0;
}

//Solved