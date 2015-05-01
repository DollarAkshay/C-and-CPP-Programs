/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/may-easy-challenge-15/algorithm/panda-and-destruction/

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


struct Edge{ int v,d;};

vector<int> graph[100001];

int con[100001];

int findMax(int n){

	int res = 0, max = 0;;
	FOR(i, 1, n){
		if (con[i] > max){
			max = con[i];
			res = i;
		}
	}
	return res;
}

int main(){

	int n, m;
	scanf("%d%d", &n,&m);
	REP(i, m){
		int u, v;
		scanf("%d%d", &u, &v);
		graph[u].push_back({ v });
		graph[v].push_back({ u});
		con[v]++;
		con[u]++;
	}
	int dest = 0;
	int u = findMax(n);
	while (u != 0){
		dest++;
		con[u] = 0;
		int s = graph[u].size();
		REP(i, s)
			con[graph[u][i]]--;
		u = findMax(n);
	}
	printf("%d\n", dest);
	return 0;
}

//Solved ~ LeL. Brute Force Wins !!