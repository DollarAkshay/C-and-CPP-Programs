/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

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

int f[259];

int focc[100005];

int main(){

	char s[100005]; 
	vector<int> wtf;
	scanf("%s", s);
	int len = strlen(s);
	REP(i, len)
		f[s[i]]++;
	REP(i, 256){
		if (f[i]){
			if (focc[f[i]] == 0)
				wtf.push_back(f[i]);
			focc[f[i]]++;
		}
	}
	if (wtf.size() > 2)
		printf("NO\n");
	else if (wtf.size() == 2 && (focc[wtf[0]]==1 || focc[wtf[1]]==1) && abs(wtf[0] - wtf[1]) == 1)
		printf("YES\n");
	else if (wtf.size()==1)
		printf("YES\n");
	else
		printf("NO\n");


}

//