
//http://www.hackerearth.com/glydel-tech-hiring-challenge/algorithm/vada-pav-list-3/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
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

char name[1000000][6];
int x = 0;

int main(){

	int n, rep;
	char temp[6];
	scanf("%d", &n);
	REP(i, n){
		scanf("%s", temp);
		rep = 0;
		REP(j, x){
			if (!strcmp(name[j], temp)){
				rep = 1;
				break;
			}
		}
		if (!rep)
			strcpy(name[x++], temp);
	}
	printf("%d\n", x);
	REP(i, x){
		FOR(j, i + 1, x - 1){
			if (strcmp(name[i], name[j])>0){
				strcpy(temp, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], temp);
			}
		}
	}
	REP(i, x)
		printf("%s\n", name[i]);

	return 0;
}

//Partially Solved 30/100