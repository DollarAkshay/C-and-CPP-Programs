/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/w17/challenges/count-fridays-the-13-th

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
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int year[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int leap[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

int dayofweek(int d, int m, int y) {
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

bool isLeapYear(int y) {
	return y%4 && (y%100!=0 || y%400==0);
}

struct date {
	int dd, mm, yyyy;
	int dayofweek;
	bool isLeap;
	bool operator<=(const date& rhs) const {
		return (yyyy<rhs.yyyy)|| (yyyy==rhs.yyyy && mm<rhs.mm) || (yyyy==rhs.yyyy && mm==rhs.mm && dd<=rhs.dd);
	}
	void increment() {
		dd++;
		dayofweek = (dayofweek+1)%7;
		if (dd>year[mm] || (isLeap && dd>leap[mm])) {
			dd = 1;
			mm++;
		}
		if (mm>12) {
			mm = 1;
			yyyy++;
			isLeap = isLeapYear(yyyy);
		}
	}
};

int main() {

	int t, n;
	scanf("%d", &t);
	REP(tc, t) {
		date d1, d2;
		int res = 0;
		scanf("%d%d%d", &d1.dd, &d1.mm, &d1.yyyy);
		d1.dayofweek = dayofweek(d1.dd, d1.mm, d1.yyyy);
		scanf("%d%d%d", &d2.dd, &d2.mm, &d2.yyyy);
		d2.dayofweek = dayofweek(d2.dd, d2.mm, d2.yyyy);
		d1.isLeap = isLeapYear(d1.yyyy);
		d2.isLeap = isLeapYear(d2.yyyy);
		for (; d1<=d2; d1.increment()) {
			if (d1.dd==13 && d1.dayofweek==5)
				res++;
		}
		printf("%d\n", res);
	}
	sp;
	return 0;
}

//