/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/exalt1/algorithm/good-numbers-3/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

char p[10000];

int good[10001];

int pd(int n){

	vector<int> dz;

	FOR(i, 2, n){
		if (p[i]){
			if (n%i== 0){
				dz.push_back(i);
				while (n%i == 0)
					n /= i;
				
			}
		}
	}
	if (dz.size() == 2)
		return 1;
	else
		return 0;
}

void seiv(){
	ll int i, j, lim = sqrt(10000);
	MS1(p);
	p[0] = p[1] = 0;
	for (i = 2; i <= lim; i++){
		if (p[i]){
			for (j = i*i; j < 10000; j += i)
				p[j] = 0;
		}
	}

}

void pre(){

	seiv();
	good[0] = 0;
	FOR(i, 1, 10000){
		if (pd(i))
			good[i] = good[i - 1] + 1;
		else
			good[i] = good[i - 1];
	}

}

int main(){

	pre();
	int n;
	scanf("%d", &n);
	printf("%d", good[n]);
	return 0;
}

//