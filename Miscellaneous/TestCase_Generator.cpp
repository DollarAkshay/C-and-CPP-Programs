#if 0

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
#include <random>
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

FILE *fp = fopen("input.txt", "w");

mt19937 mt(26640195);

ll int randomInt(ll int low, ll int high) {

	uniform_int_distribution<ll int> dist(low, high);

	return dist(mt);

}

void randomLowerString(int len) {

	REP(i, len)
		fprintf(fp, "%c", 'a'+rand()%26);
	fprintf(fp, "\n");

}

void randomString(char s, int diff, int len) {

	REP(i, len)
		fprintf(fp, "%c", s+rand()%diff);
	fprintf(fp, "\n");

}

void randomUpperString(int len) {

	REP(i, len)
		fprintf(fp, "%c", 'A'+rand()%26);
	fprintf(fp, "\n");

}

void randomArray(ll int low, ll int high, int n) {

	REP(i, n) {
		if (n%10000==0 && n>0)
			fprintf(fp, "\n");
		fprintf(fp, "%lld ", randomInt(low, high));
	}
	fprintf(fp, "\n");

}

int main() {

	ll int t = 5;
	fprintf(fp, "%lld\n", t);

	REP(tc, t) {
		int n = randomInt(10, 15), m = randomInt(10, 15);
		fprintf(fp, "%d %d\n", n, m);

		REP(i, n) {
			REP(j, m)
				fprintf(fp, "%3d ", randomInt(1, 999));
			fprintf(fp, "\n");
		}
	}

	printf("\nDONE :)\n\n");
	fclose(fp);
	sp;
	return 0;

}




#endif // 0
