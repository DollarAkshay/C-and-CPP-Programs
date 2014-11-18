
//http://www.codechef.com/MTRX2014/problems/FLITKT

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

struct flight{ char u[10], v[10]; };

struct flight f[100];

int freq[100];

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		int city, dest;
		scanf("%d", &n);
		REP(i, n){
			scanf("%s", f[i].u);
			scanf("%s", f[i].v);
		}
		REP(i, n){
			int found = 1;
			REP(j,n){
				if (!strcmp(f[i].u, f[j].v)){
					found = 0;
					break;
				}
			}
			if (found){
				city = i;
				break;
			}
		}

		REP(i, n){
			int found = 1;
			REP(j, n){
				if (!strcmp(f[i].v, f[j].u)){
					found = 0;
					break;
				}
			}
			if (found){
				dest = i;
				break;
			}
		}

		int i = city;
		while (i!=dest){
			char next[4];
			strcpy(next, f[i].v);
			printf("%s-%s ", f[i].u, f[i].v);
			REP(j, n){
				if (!strcmp(next, f[j].u)){
					i = j;
					break;
				}
			}
		}
		printf("%s-%s\n", f[i].u, f[i].v);
	}
	return 0;
}

//Solved