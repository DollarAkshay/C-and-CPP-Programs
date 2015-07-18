/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/EASYPROB/

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int i,a[] = { 137, 1315, 73, 136, 255, 1384, 16385 };

vector<int> bin[7];

vector<int> int_to_Binary(int n){

	int i = 0;
	vector<int> res;
	while (n){
		if (n%2)
			res.pb(i);
		n /= 2;
		i++;
	}
	return res;
}

void printDig(int n){

	if (n==0){
		printf("2(0)");
		return;
	}
	else if (n==1){
		printf("2");
		return;
	}
	vector<int> p = int_to_Binary(n);

	if (n!=a[i])
		printf("2(");
	FORD(i, p.size()-1, 0){
		printDig(p[i]);
		if (i)
			printf("+");
	}
	if (n!=a[i])
		printf(")");
}

int main(){

	while (i<7){
		printf("%d=",a[i]);
		printDig(a[i]);
		printf("\n");
		i++;
	}
	sp;
	
	return 0;
}

//