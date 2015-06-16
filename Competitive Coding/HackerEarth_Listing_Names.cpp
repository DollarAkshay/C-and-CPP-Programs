/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code_hunt_90-2/algorithm/listing-names-2/

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

char name[100000][31];

int main(){

	int t, n;
	scanf("%d", &t);
	getchar();
	REP(tc, t)
		scanf("%s", name[tc]);

	FOR(i, 1, t - 1){
		FOR(j, 0, t - i - 1){
			if (strcmp(name[j], name[j + 1])>0){
				char temp[32];
				strcpy(temp, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], temp);
			}
		}
	}

	REP(i, t){
		int c = 1;
		while (strcmp(name[i], name[i + 1]) == 0){
			i++;
			c++;
		}
		printf("%s %d\n", name[i], c);
	}
	return 0;
}

//Solved