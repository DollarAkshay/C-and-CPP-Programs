/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/15086967aa86622a9f16367bfcfd1ad52cc3d5a

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
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
#define DB(s,...) fprintf(stderr,s, ##__VA_ARGS__);
#define MS(x,n) memset(x,n,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007



bool comp(string l, string r){
	return l<r;
}


void Shortest_Common_Supersequence(char res[], string s){

	int DP[61][11], n = strlen(res), m = s.size();

	FOR(ii, 0, n){
		FOR(j, 0, m){
			if (j==0)
				DP[ii][j] = ii;
			else if (ii==0)
				DP[ii][j] = j;
			else if (res[ii-1]==s[j-1])
				DP[ii][j] = 1 + DP[ii-1][j-1];
			else
				DP[ii][j] = 1 + min(DP[ii-1][j], DP[ii][j-1]);
		}
	}

	char temp[61];
	int k = DP[n][m];
	temp[k--] = 0;

	int i = n, j = m;
	while (i>0 && j>0){
		if (res[i-1]==s[j-1]){
			temp[k--] = res[i-1];
			i--;
			j--;
		}
		else{
			if (DP[i-1][j]<DP[i][j-1])
				temp[k--] = res[--i];
			else
				temp[k--] = s[--j];
		}
	}
	while (i>0)
		temp[k--] = res[--i];
	while (j>0)
		temp[k--] = s[--j];

	DB("SCS = %s\n", temp);
	strcpy(res, temp);

}


	


int main(){

	int n;
	vector<string>s;

	scanf("%d", &n);
	REP(i, n){
		char ts[11];
		scanf("%s", ts);
		s.pb(ts);
	}

	sort(s.begin(), s.end());

	char res[61];
	strcpy(res,s[0].c_str());



	FOR(i,1,n-1)
		Shortest_Common_Supersequence(res, s[i]);
	
	printf("%d", strlen(res));
	
	return 0;
}

//