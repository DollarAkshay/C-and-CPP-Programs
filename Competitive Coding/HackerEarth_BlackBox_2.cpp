
//http://www.hackerearth.com/superprofs-hiring-challenge/algorithm/blackbox-2-8/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
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
#define gc getchar


#define MAX 2600


int num[MAX];

int ans[1001];

void scanint(int &x){
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

void factorialDigits(){

	int carry = 0, prod, lim = 0,i;
	num[0] = 1;
	for (int n = 1; n <= 1000; n++){
		for (i = 0; i <= lim || carry>0; i++){
			prod = num[i] * n + carry;
			carry = prod / 10;
			num[i] = prod % 10;
		}
		lim = i - 1;
		int k = i, sum = 0;
		while (k--)
			sum += num[k];
		ans[n] = sum;
	}
}



int main()
{
	factorialDigits();
	int t, n;
	scanint(t);
	for (int i = 0; i<t; i++){
		num[0] = 1;
		scanint(n);
		printf("%d\n", ans[n]);
	}
}

//Solved
