/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.tcscodevita.com/CodevitaV5/problemstart.jsp

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

char board[8][8];

string postoStr(int i, int j) {

	i= 8-i;
	string s = "";
	s += (char)(j+'a');
	s += (char)(i+'0');
	return s;

}

int main(){

	char s[1000], side;
	scanf("%s %c", s, &side);
	int len = strlen(s);
	int k = 0;

	REP(i, len) {
		if ((s[i]=='p' && side=='b')  ||  (s[i]=='P' && side=='w')) {
			board[k/8][k%8] = 'P';
			k++;
		}
		else if (s[i]>='1' && s[i]<='8') {
			REP(j, s[i]-'0') {
				board[k/8][k%8] = '_';
				k++;
			}
		}
		else if (s[i]!='/') {
			if (s[i]>='A' && s[i]<='Z')
				board[k/8][k%8] = side=='w'?'F':'E';
			else if (s[i]>='a' && s[i]<='z')
				board[k/8][k%8] = side=='b'?'F':'E';
			k++;
		}
	}

	vector<string> moves;

	REP(i, 8) {
		REP(j, 8) {
			if (board[i][j]=='P') {
				if (side=='w') {
					if (i>=1) {
						if (j>=1 && board[i-1][j-1]=='E') {
							moves.push_back(postoStr(i, j)+postoStr(i-1, j-1));
						}
						if (board[i-1][j]=='_') {
							moves.push_back(postoStr(i, j)+postoStr(i-1, j));
						}
						if (i==6 && board[i-1][j]=='_' && board[i-2][j]=='_') {
							moves.push_back(postoStr(i, j)+postoStr(i-2, j));
						}
						if (j<=6 && board[i-1][j+1]=='E') {
							moves.push_back(postoStr(i, j)+postoStr(i-1, j+1));
						}
					}
				}
				else {
					if (i<=6) {
						if (j>=1 && board[i+1][j-1]=='E') {
							moves.push_back(postoStr(i, j)+postoStr(i+1, j-1));
						}
						if (board[i+1][j]=='_') {
							moves.push_back(postoStr(i, j)+postoStr(i+1, j));
						}
						if (i==1 && board[i+1][j]=='_' && board[i+2][j]=='_') {
							moves.push_back(postoStr(i, j)+postoStr(i+2, j));
						}
						if (j<=6 && board[i+1][j+1]=='E') {
							moves.push_back(postoStr(i, j)+postoStr(i+1, j+1));
						}
					}
				}
			}
		}
	}

	printf("[");
	REP(i, moves.size()) {
		if(i==0)
			printf("%s", moves[i].c_str());
		else
			printf(", %s", moves[i].c_str());
	}
	printf("]\n");

	sp;
	return 0;
}

//