
//http://www.hackerearth.com/superprofs-hiring-challenge/algorithm/bob-an-idiot-11/

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
#define gc getchar_unlocked

char let[26];
int pos[26];

void swape(int a, int b){

	char x = let[pos[a]];
	let[pos[a]] = let[pos[b]];
	let[pos[b]] = x;
	int t = pos[b];
	pos[b] = pos[a];
	pos[a] = t;

}


int main(){

	REP(i, 26){
		let[i] = i + 'a';
		pos[i] = i;
	}

	char a, b, x;
	int n, up;
	scanf("%d", &n);
	REP(i, n){
		scanf("%c%c %c", &x, &a, &b);
		a = tolower(a);
		b = tolower(b);
		a -= 'a'; b -= 'a';
		swape(a, b);
	}
	getchar();

	while ((x = getchar())>0){
		up = 0;
		if (isupper(x)){
			up = 1;
			x = tolower(x);
		}
		up = up ? 32 : 0;
		printf("%c", let[x - 'a'] - up);
	}

	return 0;
}

//Solved 