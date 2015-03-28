/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/dandi-march-2015/algorithm/prime-numbers-again/

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

#define MAX 10000

char p[MAX+1];
int DP[1232][MAX + 1];
vector<int> primat;


void primatic(){
	ll int i, j,lim=sqrt(MAX);
	MS1(p);
	p[0] = p[1] = 0;
	for (i = 2; i <= lim; i++){
		if (p[i]){
			for (j = i*i; j <=MAX; j += i)
				p[j] = 0;
		}
	}
	for(i = 2; i <= MAX; i++){
		if (p[i]==1){
			int spec = pow(i, i);
			if (spec > MAX)
				break;
			else
				p[spec] = 2;
		}
	}
	REP(i, MAX + 1){
		if (p[i]){
			primat.push_back(i);
		}
	}
	
	FOR(j, 0, MAX) 
		DP[0][j] = j % 2 ? -1 : j / 2;


	FOR(i, 1, 1231){
		DP[i][0] = 0;
		FOR(j, 1, MAX){
			if (primat[i] > j)
				DP[i][j] = DP[i - 1][j];
			else if (primat[i] == j)
				DP[i][j] = 1;
			else{
				if (DP[i - 1][j] == -1 || (DP[i][j - primat[i]]!=-1 && 1 + DP[i][j - primat[i]] < DP[i - 1][j]))
					DP[i][j] = 1 + DP[i][j - primat[i]];
				else
					DP[i][j] = DP[i - 1][j];
			}
		}
	}

}

int main(){

	primatic();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		printf("%d\n", DP[1231][n]);
	}
	return 0;
}

//Solved