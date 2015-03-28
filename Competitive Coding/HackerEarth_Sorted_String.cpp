/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/dandi-march-2015/algorithm/sorted-string/

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

struct freq{
	int count;
	int ascii;
};

freq a[26];



bool compare(freq lhs, freq rhs) {
	return lhs.count < rhs.count;
}

int main(){

	int t;
	char str[101];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", str);
		REP(i, 26){
			a[i].ascii = i;
			a[i].count = 0;
		}

		int len = strlen(str);
		REP(i, len)
			a[str[i] - 'a'].count++;
		stable_sort(a, a + 26, compare);
		REP(i, 26){
			while (a[i].count--)
				printf("%c", a[i].ascii + 'a');
		}
		puts("");
	}
	return 0;
}

//Solved