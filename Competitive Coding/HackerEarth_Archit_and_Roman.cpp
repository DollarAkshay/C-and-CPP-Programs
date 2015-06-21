/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/archith-and-roman/

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

char symb[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

void roman(int n){

	int len, dig, power;
	while (n >= 1000)
		printf("M", n -= 1000);

	while (n>0){


		len = log10(n) + 1;
		power = pow(10, len - 1);
		dig = n / power;
		if (dig == 9){
			printf("%c%c", symb[len * 2 - 2], symb[len * 2]);
			n -= 9 * power;
		}
		else if (dig >= 5){
			printf("%c", symb[len * 2 - 1]);
			n -= 5 * power;
		}
		else if (dig == 4){
			printf("%c%c", symb[len * 2 - 2], symb[len * 2 - 1]);
			n -= 4 * power;
		}
		else if (dig >= 1){
			printf("%c", symb[len * 2 - 2]);
			n -= 1 * power;
		}
	}
}


int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		roman(n);
		printf("\n");
	}
	return 0;
}

//Solved