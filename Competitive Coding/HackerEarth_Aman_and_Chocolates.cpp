
//https://www.hackerearth.com/codathon-1/algorithm/aman-and-chocolates-1/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define ll long long
#define MOD 1000000007
#define MAX 6000000

int num[MAX];
int ans[1000001];

void preCalc(){

	num[0] = 1;
	int carry = 0, prod, n = 1, lim = 0, i;
	while (n <= 21000){
		int zero = 0;
		for (i = 0; i <= lim || carry>0; i++){
			prod = num[i] * n + carry;
			carry = prod / 10;
			if (!(num[i] = prod % 10))
				zero++;
		}
		lim = i - 1;
		char s[MAX];
		int j;
		for (j = 0; j <= lim;j++)
			s[j] = num[lim - j]+'0';
		s[j] = 0;
		ans[n] = zero;
		n++;
	}

}
int main(){

	preCalc();
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i<t; i++){
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}

//Partially Solved