/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/lets-see-how-fast-you-can-code/algorithm/execute-the-prisoners/

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

char a[100000];

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		MS0(a);
		int c = 1, i = 0, skip = 1;
		while (c<n){
			if (a[i] == 0 && skip == 0){
				a[i] = 1;
				c++;
				skip = 1;
			}
			else if (a[i] == 0 && skip == 1){
				skip = 0;
			}
			i = (i + 1) % n;
		}
		REP(j, n){
			if (a[j] == 0){
				printf("%d\n", j + 1);
				break;
			}
		}
	}
	return 0;
}

//Solved