
//http://www.hackerearth.com/problem/algorithm/starting-game-development/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
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

void scanint(int &x){
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

int bs(int a[], int key, int n){

	int low = 0, mid = -1, high = n - 1;
	while (low <= high){
		mid = (low + high) / 2;
		if (key>a[mid])
			low = mid + 1;
		else if (key<a[mid])
			high = mid - 1;
		else{
			while (a[mid] == key)mid++;
			return mid;
		}

	}
	mid = (low + high) / 2;
	return mid + 1;

}

int main(){

	int n, m, q, k;
	int str[100][5000];
	int user[100];
	scanf("%d%d%d", &n, &m, &q);
	REP(i, n)
		REP(j, m)
		scanint(str[i][j]);
	REP(i, q){
		int min = -1;
		REP(j, n){
			scanint(user[j]);
			k = bs(str[j], user[j], m);
			if (min == -1)
				min = k;
			else if (k<min){
				min = k;
				if (min == 0)
					break;
			}
		}
		cout << min << endl;

	}
	return 0;
}

//Solved 100/100