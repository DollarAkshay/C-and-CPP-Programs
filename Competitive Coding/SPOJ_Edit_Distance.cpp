/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/EDIST/

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

int DP[2001][2001];
bool compu[2001][2001];

int editDistance(char a[],char b[],int la, int lb){

	
	if (compu[la][lb])
		return DP[la][lb];

	if (la == 0)
		DP[la][lb] = lb;
	else if (lb == 0)
		DP[la][lb] = la;
	else if (a[la-1]==b[lb-1])
		DP[la][lb] = editDistance(a, b,la-1,lb-1);
	else
		DP[la][lb] = min( min(1+editDistance(a,b,la-1,lb-1), 1+editDistance(a,b,la,lb-1)), 1+editDistance(a,b,la-1,lb));
	
	compu[la][lb] = true;
	return DP[la][lb];
}

int main(){

	int t;
	char a[2001], b[2001];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", a);
		scanf("%s", b);
		printf("%d\n", editDistance(a, b, strlen(a), strlen(b)) );
		MS0(compu);
	}
	sp;
	return 0;
}

//Solved