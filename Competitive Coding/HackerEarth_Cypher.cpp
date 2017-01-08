
//http://www.hackerearth.com/cryptex/algorithm/cypher/

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

int main(){

	int t, n;
	char str[1000];
	scanf("%d", &t);
	REP(tc, t){
		cin >> str;
		int len = strlen(str);
		REP(i, len){
			int x = (str[i] - 97 + i) % 26;
			cout << (char)(x + 97);
		}
		cout << endl;
	}
	return 0;
}

//Solved