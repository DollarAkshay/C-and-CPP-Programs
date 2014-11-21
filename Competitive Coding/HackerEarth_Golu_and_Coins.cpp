
//http://www.hackerearth.com/problem/algorithm/golu-and-coins-1/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
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


int aa[10][10];

int  w[2][2] = { 1, 1, 1, 1 };
int m0[2][2] = { 0, 0, 0, 0 };
int m1[2][2] = { 1, 1, 0, 0 };
int m2[2][2] = { 1, 0, 0, 1 };

int t1[2][2] = { 0, 1, 1, 1 };
int t2[2][2] = { 1, 0, 1, 1 };
int t3[2][2] = { 1, 1, 0, 1 };
int t4[2][2] = { 1, 1, 1, 0 };

int o1[2][2] = { 1, 0, 0, 0 };
int o2[2][2] = { 0, 1, 0, 0 };
int o3[2][2] = { 0, 0, 1, 0 };
int o4[2][2] = { 0, 0, 0, 1 };

int sub[2][2];

int m, n;


int matrixCheck(int x[2][2], int y[2][2]){

	if (x[0][0] == y[0][0] &&
		x[0][1] == y[0][1] &&
		x[1][0] == y[1][0] &&
		x[1][1] == y[1][1])
		return 1;
	else
		return 0;

}

void rotMatrix(int m[2][2]){

	int temp = m[0][0];
	m[0][0] = m[1][0];
	m[1][0] = m[1][1];
	m[1][1] = m[0][1];
	m[0][1] = temp;

}

int movesFor(int s[2][2], int ib, int jb){

	if (matrixCheck(s, w))
		return 0;
	if (matrixCheck(s, m0))
		return 1;

	REP(i, 4){
		if (matrixCheck(s, m1))
			return 1;
		else
			rotMatrix(m1);
	}
	REP(i, 2){
		if (matrixCheck(s, m2))
			return 2;
		else
			rotMatrix(m2);
	}

	// Non-Inverse Case
	if ((ib>0 || jb>0) && matrixCheck(s, t1))
		return 1;

	if ((ib>0 || jb<n - 2) && matrixCheck(s, t2))
		return 1;

	if ((ib<m - 2 || jb>0) && matrixCheck(s, t3))
		return 1;

	if ((ib<m - 2 || jb<n - 2) && matrixCheck(s, t4))
		return 1;


	// Inverse Case 	
	if ((m>2 || n> 2) && matrixCheck(s, o1))
		return 2;

	if ((m>2 || n> 2) && matrixCheck(s, o2))
		return 2;

	if ((m>2 || n> 2) && matrixCheck(s, o3))
		return 2;

	if ((m>2 || n> 2) && matrixCheck(s, o4))
		return 2;



	return -1;

}


int main(){

	int ans = -1;
	scanf("%d%d", &m, &n);
	REP(i, m)
		REP(j, n)
		scanf("%d", &aa[i][j]);

	for (int i = 0; i <= m - 2; i++){
		for (int j = 0; j <= n - 2; j++){
			sub[0][0] = aa[i][j];
			sub[0][1] = aa[i][j + 1];
			sub[1][0] = aa[i + 1][j];
			sub[1][1] = aa[i + 1][j + 1];
			int mov = movesFor(sub, i, j);
			if (mov != -1){
				if (ans == -1)
					ans = mov;
				else if (mov<ans)
					ans = mov;
			}
		}
	}

	printf("%d", ans);
	return 0;
}

// Partially Solved