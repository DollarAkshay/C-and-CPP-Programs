
//http://www.hackerearth.com/tcetcyphers-4/algorithm/string-and-primes/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
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
struct Edge{ int v, w; };

int p[256];

void seiv(){
	MS1(p);
	long int i, j, k;
	p[0] = p[1] = 0;
	int lim = sqrt(256);
	for (i = 2; i <= lim; i++){
		if (p[i]){
			for (j = i*i; j<256; j += i){
				if (p[j])
					p[j] = 0;
			}
		}
	}
}



int main(){

	seiv();
	int t, n, i, j;
	char str[100001], x, del[100001];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%c%s", &x, str);
		int len = strlen(str);
		for (i = 0, j = 0; i<len; i++){
			if (p[str[i]] == 0){
				del[j++] = str[i];
			}
		}
		del[j] = '\0';
		if (j == len){
			printf("NULL\n");
		}
		else
			printf("%s\n", del);
	}
	return 0;
}

//Solved