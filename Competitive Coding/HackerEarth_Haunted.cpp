/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/haunted/

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
#define gc getchar_unlocked
struct Edge{ int v, w; };

struct ghost{
	int n, a;
};

vector<ghost> f;

void scanint(int &x){
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

int main()
{
	int n, m, t, max = 0, pos, i, j, size;
	scanint(n);
	scanint(m);
	for (i = 0; i<n; i++){
		scanint(t);
		char found = 0;
		size = f.size();
		for (j = 0; j<size; j++){
			if (f[j].n == t){
				found = 1;
				f[j].a++;
				break;
			}
		}
		if (!found)
			f.push_back({ t, 1 });

		if (f[j].a > max){
			pos = f[j].n;
			max = f[j].a;
		}
		else if (f[j].a == max && f[j].n>pos)
			pos = f[j].n;

		printf("%d %d\n", pos, max);
	}
}

//Partially Solved ~ TLE