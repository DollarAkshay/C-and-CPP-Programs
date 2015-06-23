/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/150711047ccf54f2b565001dfe092c497dd1dc5

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

int main(){

	int n, a[100000],ans=0,h;
	scanf("%d", &n);
	REP(i,n){
		scanf("%d", &a[i]);
		if (i){
			h = max(h, a[i]);
			if (a[i] < a[i - 1]){
				ans = min(ans, a[i] - h);
			}
		}
		else
			h = a[0];

	}
	printf("%d", ans);
	return 0;
}

//