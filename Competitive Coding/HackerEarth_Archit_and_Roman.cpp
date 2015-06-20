/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codestellar-3/algorithm/archith-and-roman/

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

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		while (n){
			if (n == 100){
				printf("C");
				n -= 100;
			}
			else if (n >= 90){
				printf("XC");
				n -= 90;
			}
			else if (n >= 50){
				printf("L");
				n -= 50;
			}
			else if (n >= 40){
				printf("XL");
				n -= 40;
			}
			else if (n >= 10){
				while (n >= 10){
					printf("X");
					n -= 10;
				}
			}
			else if (n == 9){
				printf("IX");
				n -= 9;
			}
			else if (n >= 5){
				printf("V");
				n -= 5;
			}
			else if (n == 4){
				printf("IV");
				n -= 4;
			}
			else {
				while (n){
					printf("I");
					n--;
				}
			}
		}
		printf("\n");
	}
	return 0;
}

//Solved