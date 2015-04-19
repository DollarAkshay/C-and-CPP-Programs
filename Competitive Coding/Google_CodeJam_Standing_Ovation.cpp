/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://code.google.com/codejam/contest/6224486/dashboard#s=p0

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

	FILE *fp = fopen("data2.txt", "w");

	vector<int>a;
	int t, n;
	char str[1002];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d %s", &n,str);
		a.clear();
		int len = strlen(str);
		REP(i, len){
			while (str[i] != '0'){
				a.push_back(i);
				str[i]--;
			}
		}
		int size = a.size(),x=0;
		REP(i, size){
			x = max(x, a[i] - i);
		}
		fprintf(fp,"Case #%d: %d\n", tc + 1, x);
	}
	fclose(fp);
	sp;
	return 0;
}

//Solved