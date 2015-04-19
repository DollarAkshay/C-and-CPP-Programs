/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/lets-see-how-fast-you-can-code/algorithm/sumit-and-indian-currency/

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

	int t, n;
	char s[10005];
	scanf("%d", &t);
	getchar();
	REP(tc, t){
		scanf("%s", s);
		getchar();
		int len = strlen(s);
		FOR(i, 0, len - 4){
			if ((len - i - 1) % 2)
				printf("%c,", s[i]);
			else
				printf("%c", s[i]);
		}
		if (len - 3 >= 0)
			printf("%c", s[len - 3]);
		if (len - 2 >= 0)
			printf("%c", s[len - 2]);
		if (len - 1 >= 0)
			printf("%c\n", s[len - 1]);
	}
	return 0;
}

//Solved