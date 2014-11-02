
//http://www.hackerearth.com/iitkgpheoct14/algorithm/the-substring-problem-1/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
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

int f[26], c[26];

int main(){

	int t, n;
	char str[101], x;
	scanf("%d", &t);
	REP(tc, t){
		MS0(f);
		scanf("%d", &n);
		REP(i, n){
			scanf("%c%s", &x, str);
			int len = strlen(str);
			MS0(c);
			REP(j, len){
				if (!c[str[j] - 'a']){
					f[str[j] - 'a']++;
					c[str[j] - 'a']++;
				}
			}
		}

		int max = f[0], pos = 0;
		REP(i, 26){
			if (f[i]>max){
				max = f[i];
				pos = i;
			}
		}
		printf("%c\n", 'a' + pos);

	}
	return 0;
}

//Solved