/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code-mania-100/algorithm/get-time-in-words-now-1/

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
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int a[100000];

string toEnglish(int n) {

	if (n==0)
		return "zero";
	else if (n==1)
		return "one";
	else if (n==2)
		return "two";
	else if (n==3)
		return "three";
	else if (n==4)
		return "four";
	else if (n==5)
		return "five";
	else if (n==6)
		return "six";
	else if (n==7)
		return "seven";
	else if (n==8)
		return "eight";
	else if (n==9)
		return "nine";
	else if (n==10)
		return "ten";
	else if (n==11)
		return "eleven";
	else if (n==12)
		return "twelve";
	else if (n==13)
		return "thirteen";
	else if (n==14)
		return "fourteen";
	else if (n==15)
		return "fifteen";
	else if (n>=16 && n<=19)
		return toEnglish(n%10)+"teen";
	else if (n==20)
		return "twenty";
	else if (n>=21 && n<=29)
		return "twenty"+toEnglish(n%10);
	else if (n==30)
		return "thirty";
}

int main(){

	int h, m;
	scanf("%d %d", &h, &m);
	if (m<=30) {
		if (m==0)
			printf("%s o' clock\n", toEnglish(h).c_str());
		else if(m==1)
			printf("%s minute past %s\n", toEnglish(m).c_str(), toEnglish(h).c_str());
		else if(m==15)
			printf("quarter past %s\n", toEnglish(h).c_str());
		else if (m==30)
			printf("half past %s\n", toEnglish(h).c_str());
		else
			printf("%s minutes past %s\n", toEnglish(m).c_str(), toEnglish(h).c_str());
	}
	else {
		if (m==45)
			printf("quarter to %s\n", toEnglish((h+1)%12).c_str());
		else
			printf("%s minutes to %s\n", toEnglish(60-m).c_str(), toEnglish((h+1)%12).c_str());
	}
}

//Solved