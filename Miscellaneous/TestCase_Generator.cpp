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

	int n = 100;
	fprintf(fp, "100 100\n", rand() % 19 - 9);
	REP(i, n)
		fprintf(fp, "%d ", rand()%19-9);

	printf("\n");
	REP(i, n){
		int l = rand() % n;
		int r = rand() % (n - l) + l;
		fprintf(fp, "%d %d\n",l,r);
	}

	fclose(fp);
	printf("Done\n");
	sp;
	return 0;
}

//