
//http://www.codechef.com/MTRX2014/problems/DATE

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

int year[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int leap[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(){

	int t,d,m,y,l;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d/%d/%d", &d,&m,&y);
		l= y%4==0 && (y%100!= 0||y%400==0) ? 1: 0;
		if (m > 12 || d >(l?leap[m-1]:year[m-1]) )
			puts("Invalid Date\n");
		else{
			d++;
			if (d >(l?leap[m-1]:year[m-1])){
				d = 1;
				m++;
				if (m>12){
					m = 1;
					y++;
				}
			}
			printf("%d/%d/%d\n", d, m, y);
		}
	}
	return 0;
}

//