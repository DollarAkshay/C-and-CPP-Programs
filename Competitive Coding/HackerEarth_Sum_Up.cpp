/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/CodeTreat1/algorithm/sum-up-5/

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007


int print[200];

void partitn(int n, int k, int idx){

	if (n==0){
		if (idx==1)
			printf("%d\n", print[0]);
		else{
			for (int i = 0; i<idx; i++)
				printf("%d ", print[i]);
			printf("\n");
		}
		return;
	}


	for (int i = k; i>0; i--){
		if (i>n)
			continue;
		print[idx] = i;
		partitn(n-i, i, idx+1);
	}

}

int main(){

	int n = -1;
	char s[100];
	scanf("%d", &n);
	partitn(n, n, 0);

	return 0;
}

//Solved