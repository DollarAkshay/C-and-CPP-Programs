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

FILE *fp = fopen("testcase.txt", "w");

void randomLowerString(int len) {

	REP(i, len) 
		fprintf(fp, "%c", 'a'+rand()%26);
	fprintf(fp, "\n");

}

void randomUpperString(int len) {

	REP(i, len)
		fprintf(fp, "%c", 'A'+rand()%26);
	fprintf(fp, "\n");

}

int main(){

	srand(time(NULL));


	int n = 1000;
	int t = rand()%n;
	fprintf(fp, "%d %d\n",n, t);
	randomLowerString(n);
	randomLowerString(n);
	fclose(fp);
	printf("Done\n");
	sp;
	return 0;
}

//