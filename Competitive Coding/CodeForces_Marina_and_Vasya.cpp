/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/584/problem/C

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
#include <functional>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MSX(a,x) memset(a,x,sizeof(a))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

char s1[100001], s2[100001], s3[100001];

char getDiff(char s1, char s2) {
	if (s1!='a' && s2!='a')
		return 'a';
	else if (s1!='z' && s2!='z')
		return 'z';
	else
		return 'k';
}

int diference(char *s1, char *s2,int len) {
	int res = 0;
	REP(i, len)
		if (s1[i]!=s2[i])
			res++;
	return res;
}


int main(){

	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", s1);
	scanf("%s", s2);
	int diff = 0, same = 0;
	REP(i, n) {
		if (s1[i]!=s2[i])
			diff++;
		else
			same++;
	}
	if (diff>k*2) {
		printf("-1");
	}
	else {
		memset(s3, 'A', n);
		int pos=-1;
		REP(i, n) {
			if (s1[i]!=s2[i]) {
				if (pos==-1) {
					if (diff<k*2) {
						s3[i] = getDiff(s1[i], s2[i]);
						diff--;
						k--;
					}
					else
						pos = i;
				}
				else {
					s3[pos] = s1[pos];
					s3[i] = s2[i];
					pos = -1;
					diff -= 2;
					if (--k==0)
						break;
				}
			}
		}
		if (k>0) {
			REP(i, n) {
				if (s1[i]==s2[i]) {
					s3[i] = s1[i] =='a'?'z':'a';
					if (--k==0)
						break;
				}
			}
		}

		REP(i, n) {
			if (s3[i]=='A')
				s3[i] = s2[i];
		}

		printf("%s\n", s3);
		//printf("%d vs %d\n", diference(s1, s3, n), diference(s2, s3, n));
	}
	//sp;
	return 0;
}

//Solved