/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/encryption

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

char str[82];
char box[10][10];

int main(){
	cin >> str;
	int len = strlen(str);
	int w = ceil(sqrt(len));
	int h = floor(sqrt(len));
	if (w*h < len)
		h++;
	REP(i, h){
		REP(j, w){
			box[i][j] = str[i*w + j];
		}
	}
	REP(i, w){
		REP(j, h){
			if (box[j][i])
				printf("%c", box[j][i]);
		}
		printf(" ");
	}
	sp;
	return 0;
}

//Solved