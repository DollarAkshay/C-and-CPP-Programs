//https://www.hackerrank.com/contests/projecteuler/challenges/euler004

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include<assert.h>
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

int isPalindrome(int n){
	int rev = 0, t = n;
	while (t){
		rev = rev * 10 + t % 10;
		t /= 10;
	}
	if (rev == n)
		return 1;
	else
		return 0;
}

int isMultiple(int n){

	int lim = sqrt(n);
	for (int i = 100; i <= lim; i++){
		if (n%i == 0 && n / (i * 1000) == 0){
			return 1;
		}
	}
	return 0;
}

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		FORD(i, n - 1, 100000){
			if (isPalindrome(i) && isMultiple(i)){
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}

//Solved