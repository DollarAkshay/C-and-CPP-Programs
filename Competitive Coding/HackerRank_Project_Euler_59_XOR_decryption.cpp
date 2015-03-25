/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/projecteuler/challenges/euler059

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

int str[3][500];


int main(){

	int n;
	char key[4];
	scanf("%d", &n);
	REP(i, n) scanf("%d", &str[i % 3][i / 3]);

	for (int k = 0; k < 3; k++){
		FOR(i, 'a', 'z'){
			int found = 1, j = 0;
			while (j<n/3){
				char res = str[k][j] ^ i;
				if (isalnum(res) || res == ' ' || res == '(' || res == ')' ||
					res == ';' || res == ':' || res == ',' || res == '.' ||
					res == 39 || res == '?' || res == '-' || res == '!')
					j++;
				else{
					found = 0;
					break;
				}
			}
			if (found){
				key[k] = i;
				break;
			}
		}
	}
	key[3] = 0;
	puts(key);
	int sum = 0;
	REP(i, n){
		char c = str[i % 3][i / 3] ^ key[i % 3];
		printf("%c", c);
		sum +=c;
	}
	printf("\n%d\n",sum);
	sp;
	return 0;
}

//Solved