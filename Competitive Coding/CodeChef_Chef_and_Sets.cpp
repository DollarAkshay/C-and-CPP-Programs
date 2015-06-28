/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/LTIME25/problems/CHEFDTRE

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

vector<int> s[200000];

void merge(int a, int b, int c){

	int i, j;
	for (i = 0, j = 0; i < s[a].size() && j < s[b].size();){
		if (s[a][i] < s[b][j]){
			s[c].push_back(s[a][i]);
			i++;
		}
		else{
			s[c].push_back(s[b][j]);
			j++;
		}
	}

	while (i < s[a].size())
		s[c].push_back(s[a][i++]);
	
	while (j < s[b].size())
		s[c].push_back(s[b][j++]);

}




int main(){

	int n, q,a,b;
	scanf("%d %d", &n, &q);
	FOR(i, 1, n)
		s[i].push_back(i);
	n++;

	REP(i, q){
		char str[10];
		scanf("%s %d %d", str, &a, &b);
		if (str[0] == 'U'){
			merge(a, b, n);
			n++;
		}
		else{
			printf("%d\n",s[a][b-1]);
		}
	}
	sp;
	return 0;
}

//