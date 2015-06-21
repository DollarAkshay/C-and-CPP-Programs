/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/COOK59/problems/ANKPAREN

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

char s[100001];

void debug(int pos,int len){

	REP(i, len)
		if (i != pos)
			printf("%d", s[i]-'(');
	printf(" ...\n");
}

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", s);
		scanf("%d", &n);
		int len=strlen(s),l = 0, r = 0,reg;
		REP(i, len)
			s[i] == '('?l++:r++;
		reg = l == r?1:0;
		if (!reg){
			if (n == 1)
				printf("%s", s);
			else
				printf("-1");
		}
		else{
			int pos, perm = 0;
			REP(i, len){
				if (s[i] == ')'){
					perm++;
					if (perm == n){
						pos = i;
						break;
					}
					while (s[i + 1] == s[i])
						i++;
				}
			}
			if (perm < n){
				FORD(i, len - 1, 0){
					if (s[i] == '('){
						perm++;
						if (perm == n){
							pos = i;
							break;
						}
						while (s[i - 1] == s[i])
							i--;
					}
				}
			}
			if (perm==n){
				REP(i, len)
					if (i != pos)
						printf("%c", s[i]);
			}
			else
				printf("-1");
		}
		printf("\n");
	}
	sp;
	return 0;
}

//I think I have solved it but its not working :(