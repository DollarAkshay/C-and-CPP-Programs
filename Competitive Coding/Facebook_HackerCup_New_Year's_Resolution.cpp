/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

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

struct food{
	int p, c, f;
}alex, a[20];


int checkFood(int s){

	int tp=0, tc=0, tf=0, k=0;
	while (s){
		if (s % 2){
			tp += a[k].p;
			tc += a[k].c;
			tf += a[k].f;
		}
		s >>= 1; k++;
	}
	if (tp == alex.p && tc == alex.c && tf == alex.f)
		return 1;
	else
		return 0;

}

int main(){

	FILE *f = fopen("myfile.txt", "w");
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d%d", &alex.p,&alex.c,&alex.f);
		scanf("%d", &n);
		REP(i, n)
			scanf("%d%d%d", &a[i].p, &a[i].c, &a[i].f);
		
		int subsets = pow(2, n), found = 0;;
		REP(i, subsets){
			if (checkFood(i)){
				found = 1;
				break;
			}
		}
		fprintf(f, "Case #%d: ", tc + 1);
		fputs(found ? "yes\n" : "no\n",f);
	}
	return 0;
}

//