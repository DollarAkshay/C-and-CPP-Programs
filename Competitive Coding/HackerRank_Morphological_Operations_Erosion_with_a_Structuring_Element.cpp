/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/dip-morphological-operations-erosion-with-a-structuring-element

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

char img[100][100];
char kernel[10][10] = { { 1, 0},{ 1, 1} };

int row, col;
int krow = 2, kcol = 2;
int xmid = 0, ymid = 1;

void dilate() {

	char imcopy[100][100];

	REP(i, row) {
		REP(j, col) {
			imcopy[i][j] = img[i][j];
			REP(ki, krow) {
				REP(kj, kcol) {
					int px = j + (kj-xmid), py = i + (ki-ymid);
					if (px>=0 && px<col && py>=0 && py<row)
						imcopy[i][j] = max(imcopy[i][j], (char)(img[py][px]*kernel[ki][kj]));

				}
			}

		}
	}

	REP(i, row) {
		REP(j, col)
			img[i][j] = imcopy[i][j];
	}
}

int main() {


	while (scanf("%[^\n]", img[row])>0) {
		getchar();
		row++;
		if (row==3)
			break;
	}

	col = strlen(img[0]);

	dilate();

	int c = 0;
	REP(i, row) {
		REP(j, col) {
			printf("%c", img[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", c);

	sp;
	return 0;
}

//Solved