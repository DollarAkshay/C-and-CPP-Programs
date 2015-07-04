/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/


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

	srand(time(NULL));
	FILE *fp = fopen("testcase.txt", "w");

	int t = 2;
	
	fprintf(fp, "%d\n", t);
	REP(tc, t){
		int n = 8;
		int k = rand() % 10 + 5;
		int m = rand() % 4 + 3;
		fprintf(fp, "\n%3d %3d %3d\n", n, k, m);
		REP(i, n)
			fprintf(fp, "%3d ", rand()%30-15);
		REP(i, m){
			int l = rand()%n;
			int r = l + rand() % (n - l);
			int c = rand() %5+3;
			fprintf(fp, "%3d %3d %3d\n", l, r, c);
		}
		
	}
	fclose(fp);
	printf("Done\n");
	sp;
	return 0;
}

//