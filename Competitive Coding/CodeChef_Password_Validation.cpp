/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/SPT2015/problems/SPIT3

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

int main(){

	int c1=0, c2=0, c3=0, c4=0;
	char str[101];
	scanf("%s", str);
	int len = strlen(str);
	if (len >= 5)
		c1 = 1;
	REP(i, len){
		if (isupper(str[i]))
			c2 = 1;
		if (islower(str[i]))
			c3 = 1;
		if (isdigit(str[i]))
			c4 = 1;
	}
	puts(c1&&c2&&c3&&c4 ? "YES" : "NO");

	return 0;
}

//