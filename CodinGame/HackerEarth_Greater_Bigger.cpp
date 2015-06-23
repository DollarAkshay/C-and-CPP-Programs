/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code_hunt_100-1/algorithm/greater-bigger/

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
#include <stack>
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

char s1[100000], s2[100000];

void swap(char *c1, char *c2){
	char t = *c1;
	*c1 = *c2;
	*c2 = t;
}


int find(int l){

	int i = l - 1;
	while (s2[i] <= s2[i - 1])
		i--;

	if (i == 0)
		return 0;
	else{
		char c = s2[i - 1];
		int j = i - 1;
		while (j + 1<l && s2[j + 1]>c)
			j++;
		s2[i - 1] = s2[j];
		s2[j] = c;
		sort(begin(s2) + i, begin(s2) + l);
		return 1;
	}
}

int main(){


	int t;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", s1);
		strcpy(s2, s1);
		int l = strlen(s1);
		if (find(l))
			printf("%s\n", s2);
		else
			puts("no answer");

	}
	return 0;
}

//Solved