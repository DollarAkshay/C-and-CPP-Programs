/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence

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

int DP[101][101];
bool computed[101][101];

int LCS(int s1[], int s2[], int n, int m){

	if (computed[n][m]==1)
		return DP[n][m];

	if (n==-1 || m==-1)
		DP[n][m] = 0;
	else{
		if (s1[n]==s2[m])
			DP[n][m] = 1 + LCS(s1, s2, n-1, m-1);
		else
			DP[n][m] = max(LCS(s1, s2, n-1, m), LCS(s1, s2, n, m-1));
	}

	computed[n][m]=1;
	return DP[n][m];

}

int main(){

	int n, m;
	int s1[101], s2[101], c;
	scanf("%d%d", &n, &m);
	REP(i, n)
		scanf("%d", &s1[i]);
	REP(i, m)
		scanf("%d", &s2[i]);

	LCS(s1, s2, n-1, m-1);

	int i = n-1, j = m-1;
	vector<int> seq;

	while (i>=0 && j>=0){
		if (s1[i]==s2[j]){
			seq.pb(s1[i]);
			i--;
			j--;
		}
		else{
			if (DP[i-1][j]>DP[i][j-1])
				i--;
			else
				j--;
		}
	}

	FORD(i, seq.size()-1, 0)
		printf("%d ", seq[i]);
	sp;
	return 0;
}

//Solved