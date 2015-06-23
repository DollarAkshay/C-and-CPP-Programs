/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/15085145ad8bd81d4f022f8c787b688414e438f

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

	int r, l,s=1;
	int a[10000],b[10000];
	scanf("%d%d", &r, &l);
	a[0] = r;
	REP(i, l-1){
		int k = 0;
		REP(j, s){
			int c = 1;
			while (j + 1 < s && a[j] == a[j + 1]){
				j++;
				c++;
			}
			b[k++] = c;
			b[k++] = a[j];
		}
		s = k;
		REP(j, k)
			a[j] = b[j];
	}
	REP(i, s)
		if (i)
			printf(" %d", a[i]);
		else
			printf("%d", a[i]);

	return 0;
}

//