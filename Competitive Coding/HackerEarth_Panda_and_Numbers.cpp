/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/may-easy-challenge-15/algorithm/panda-and-numbers/

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
#define gc getchar_unlocked
struct Edge{ int v, w; };

vector<int> pand;

int p[11];

int ispand[1000000];

int caclPand(int x){

	if (x < -1)
		return 0;
	if (x == 0)
		return 0;
	REP(i, 10){
		if (x == p[i])
			return 1;
	}

	int lim = log10(x) + 1;
	REP(i, lim){
		int div = pow(10,i);
		int dig = x / div % 10;
		int n = x - dig*dig;
		if (dig && caclPand(n))
			return 1;
	}
	return 0;
}

void pre(){

	REP(i, 11)
		p[i] = pow(i-1, i-1);
	

	FOR(i, 0, 50000){
		if (caclPand(i))
			ispand[i] = 1;
		else
			pand.push_back(i);
	}

	cout << "Done";
}

int main(){

	pre();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
	}
	return 0;
}

//Brute Force Testing ~ Dosent Work