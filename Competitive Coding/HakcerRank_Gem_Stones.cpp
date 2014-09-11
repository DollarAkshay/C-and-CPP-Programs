#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,n-1)
#define ll long long

int main(){

	static int letter[26];
	int round[26];
	char c;
	int n, cnt = 0;
	scanf("%d", &n);
	scanf("%c", &c);
	REP(i, n){
		while (scanf("%c", &c)>0 && c>96){
			if (round[c - 97] == 0){
				letter[c - 97]++;
				round[c - 97] = 1;
			}
		}
		memset(round, 0, sizeof(round));
	}
	REP(i, 26){
		if (letter[i] == n)
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}