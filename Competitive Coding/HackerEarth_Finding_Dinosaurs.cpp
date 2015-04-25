/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/broadridge-codebee/algorithm/finding-dinosaurs-1/

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

int main(){

	int n, k, q, l;
	char dino[100000][11];
	char att[100000][6];
	scanf("%d%d%d%d", &n, &k, &l, &q); 
	getchar();
	REP(i, n){
		scanf("%s",dino[i]);
		REP(j, k){
			int x;
			scanf("%d", &x);
			att[i][j] = x + '0';
		}
		att[i][k] = 0;
	}
	REP(i, q){
		char ques[6],dummy=0;
		REP(j, k){
			int x;
			scanf("%d", &x);
			if (x > l)
				dummy = 1;
			ques[j] = x + '0';
		}
		ques[k] = 0;
		if (dummy)
			printf("You cant fool me :P\n");
		else{
			dummy = 1;
			REP(j, n){
				if (!strcmp(att[j], ques)){
					dummy = 0;
					printf("%s\n", dino[j] );
					break;
				}
			}
			if (dummy)
				printf("You cant fool me :P\n");
		}
	}

	return 0;
}

//Partally Solved ~ TLE