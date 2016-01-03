/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int main(){

	FILE* out = fopen("C:\\Users\\Akshay L Aradhya\\Desktop\\reslut.pal", "w");
	
	fprintf(out, "%c%c%c%c%c%c%c%c", 0x52, 0x49, 0x46, 0x46, 0x10, 0x04, 0x00, 0x00);
	fprintf(out, "%c%c%c%c%c%c%c%c", 0x50, 0x41, 0x4C, 0x20, 0x64, 0x61, 0x74, 0x61);
	fprintf(out, "%c%c%c%c%c%c%c%c", 0x04, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01);
	printf("Enter RGB Values :\n");
	REP(i, 256) {
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		fprintf(out, "%c%c%c%c", (char)r%256, (char)g%256, (char)b%256, 0);
	}
	fclose(out);
	sp;
	return 0;
}

//