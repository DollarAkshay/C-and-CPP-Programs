/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/560/problem/D

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

char s1[200001], s2[200001];

bool eq(char s1[], char s2[], int l1, int l2){

	if (l1!=l2)
		return false;
	if (l1%2==1){
		if (strncmp(s1, s2, l1)==0)
			return true;
		else
			return false;
	}
	else{
		if (strncmp(s1, s2, l1)==0)
			return true;
		else{
			int mid = l1/2;
			return ((eq(s1, s2, mid, mid) && eq(s1+mid, s2+mid, mid, mid)) ||
					(eq(s1+mid, s2, mid, mid) && eq(s1, s2+mid, mid, mid)));
		}
	}
}

int main(){

	scanf("%s", s1);
	scanf("%s", s2);
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	clock_t ti = clock();
	puts(eq(s1,s2,l1,l2)?"YES":"NO");
	printf("Time = %f\n", (float)(clock()-ti)/CLOCKS_PER_SEC);
	sp;
}

//