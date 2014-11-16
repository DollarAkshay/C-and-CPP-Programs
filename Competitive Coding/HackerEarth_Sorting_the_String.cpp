
//http://www.hackerearth.com/tcetcyphers-4/algorithm/sorting-the-string/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
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
	char str[100005], x;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%c%s%d", &x, str, &n);
		int len = strlen(str);
		SORT(str, len);
		if (n % 2){
			int c = 0;
			FORD(i, len - 1, 0){
				if (isupper(str[i])){
					c++;
					printf("%c", str[i]);
				}
			}
			if (c == 0)
				printf("NULL");
			printf("\n");
		}
		else{
			int c = 0;
			FOR(i, 0, len - 1){
				if (isupper(str[i])){
					c++;
					printf("%c", str[i]);
				}
			}
			if (c == 0)
				printf("NULL");
			printf("\n");
		}
	}
	return 0;
}

//Solved