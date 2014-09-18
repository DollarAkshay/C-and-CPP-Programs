
//http://www.hackerearth.com/tcetcyphers-2/algorithm/vaishnav-and-factorials/

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


int num[495];

int getZero(){
	int i = 494;
	while (num[i] == 0 && i)i--;
	return i;

}

void factorial(int n){
	int carry = 0, prod;
	while (n){
		for (int i = 0; i <= getZero() || carry>0; i++){
			prod = num[i] * n + carry;
			carry = prod / 10;
			num[i] = prod % 10;
		}
		n--;
	}
}

void printArray(){
	int i = 495, c = 0;
	while (i--) {
		if (num[i] == 4 || num[i] == 7)
			c++;
	}
	printf("%d\n", c);
}

int main()
{
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i<t; i++){
		num[0] = 1;
		scanf("%d", &n);
		factorial(n);
		printArray();
		MS0(num);
	}
}

//Solved