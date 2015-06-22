/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/150028832ac467de1e6e189166ab710ed9ccd97

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
#include <string>
#include <stack>
#include <map>
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

vector<pair<string ,string>> ext;

int main(){

	char s1[257], s2[257];
	int n, q;
	scanf("%d%d", &n, &q);
	REP(i, n){
		scanf("%s %s", s1, s2);
		int l1 = strlen(s1), l2 = strlen(s2);
		REP(j, l1)
			if (isupper(s1[j]))
				s1[j] += 32;
		REP(j, l2){
			if (isupper(s2[j]))
				s2[j] += 32;
		}
		ext.push_back(make_pair(s1,s2));
	}

	REP(i, q){
		scanf("%s", s1);
		int l1 = strlen(s1);
		REP(j, l1)
			if (isupper(s1[j]))
				s1[j] += 32;
		int x = (int)(strrchr(s1, '.') - s1 + 1);
		fprintf(stderr, "X = %d\n", x);
		x = x < 0 ?strlen(s1):x;
		strcpy(s2, s1 + x);
		int pos = -1,size = ext.size();
		REP(j, size){
			if (strcmp(ext[j].first.c_str(), s2) == 0){
				pos = j;
				break;
			}
		}
		if (pos==-1)
			puts("UNKNOWN");
		else
			printf("%s\n", ext[pos].second.c_str());
			
	}
	return 0;
}

//