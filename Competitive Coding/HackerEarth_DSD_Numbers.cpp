/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codezarena-v2/algorithm/dsd-numbers/

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



int digsum(ll int n){
	int res = 0;
	while (n > 0){
		res += n % 10;
		n /= 10;
	}
	return res;
}

vector<int>dsd,tst;

void pre(){

	int s = 0;
	FOR(i, 1, 100000000){
		s++;
		int n = i;
		while (n % 10 == 0){
			s -= 9;
			n /= 10;
		}
		if (i%s == 0)
			dsd.push_back(i);
		
	}
	cout << "Done";
}


int main(){

	pre();
	int t, l,r;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &l,&r);
		int c = 0;
		FOR(i, l, r){
			int s = digsum(i);
			if (i%s == 0) c++;
		}
		printf("%d\n",c);
	}
	return 0;
}

//partially solved
