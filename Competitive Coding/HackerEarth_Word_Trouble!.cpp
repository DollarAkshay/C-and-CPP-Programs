/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/CodeTreat1/algorithm/word-trouble/

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

int a[100000];

int main(){

	int t, n;
	char s1[100], s2[100];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", s1);
		scanf("%s", s2);
		getchar();
		int l1 = strlen(s1), l2 = strlen(s2);
		int match = 0;
		REP(i, min(l1, l2)){
			if (s1[i]==s2[i]){
				match++;
			}
		}
		if (match == l1 && l1==l2)
			printf("Exact\n");
		else
			printf("Non Exact %d\n", max(l1, l2)-match);

	}
	return 0;
}

//Solved