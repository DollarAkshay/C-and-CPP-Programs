
//http://www.spoj.com/problems/NSYSTEM/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <ctype.h>
#include <cstdio>
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

struct MCXI {
	int m, c;
	int x, i;
	int value;
};

char fix[1001];

void Deci_MCXI(int n){

	fix[1000] = 'm';
	fix[100] = 'c';
	fix[10] = 'x';
	fix[1] = 'i';

	int pow = 1000;
	while (pow){
		if (n / pow){
			if (n / pow > 1)
				printf("%d%c", n / pow, fix[pow]);
			else
				printf("%c", fix[pow]);
		}
		n %= pow;
		pow /= 10;
	}
	printf("\n");
}


int main(){
	int t, n, len;
	MCXI n1, n2;
	char l1[100], x;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%c%s", &x, l1);

		len = strlen(l1);


		n1.value = 0;
		REP(i, len){
			if (l1[i] == 'm'){
				if (i && isdigit(l1[i - 1]))
					n1.m = l1[i - 1] - '0';
				else
					n1.m = 1;
				n1.value += n1.m * 1000;
			}
			else if (l1[i] == 'c'){
				if (i && isdigit(l1[i - 1]))
					n1.c = l1[i - 1] - '0';
				else
					n1.c = 1;
				n1.value += n1.c * 100;
			}
			else if (l1[i] == 'x'){
				if (i && isdigit(l1[i - 1]))
					n1.x = l1[i - 1] - '0';
				else
					n1.x = 1;
				n1.value += n1.x * 10;
			}
			else if (l1[i] == 'i'){
				if (i && isdigit(l1[i - 1]))
					n1.i = l1[i - 1] - '0';
				else
					n1.i = 1;
				n1.value += n1.i;
			}
		}
		scanf("%c%s", &x, l1);
		len = strlen(l1);
		n2.value = 0;
		REP(i, len){
			if (l1[i] == 'm'){
				if (i && isdigit(l1[i - 1]))
					n2.m = l1[i - 1] - '0';
				else
					n2.m = 1;
				n2.value += n2.m * 1000;
			}
			else if (l1[i] == 'c'){
				if (i && isdigit(l1[i - 1]))
					n2.c = l1[i - 1] - '0';
				else
					n2.c = 1;
				n2.value += n2.c * 100;
			}
			else if (l1[i] == 'x'){
				if (i && isdigit(l1[i - 1]))
					n2.x = l1[i - 1] - '0';
				else
					n2.x = 1;
				n2.value += n2.x * 10;
			}
			else if (l1[i] == 'i'){
				if (i && isdigit(l1[i - 1]))
					n2.i = l1[i - 1] - '0';
				else
					n2.i = 1;
				n2.value += n2.i;
			}
		}

		Deci_MCXI(n1.value + n2.value);

	}
	return 0;
}

// Solved