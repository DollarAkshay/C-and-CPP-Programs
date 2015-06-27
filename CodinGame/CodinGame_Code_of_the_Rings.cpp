/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/14827207045a2123c4c8d91e5e7897be5fbc8be

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
#include <string>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(s,x) fprintf(stderr,s,x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
struct point{
	int x, y;
};

char a[27] = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char s[1000],rune[30];
string brainfuck;
int len, x;
int pos[255];


void init(){

	x = 0;
	REP(i, 27)
		pos[a[i]] = i;
	REP(i, 30)
		rune[i] = ' ';

}

int idMOD(int x,int mod,int dir){

	if (dir > 0){
		REP(i, abs(dir))
			x = (x + 1) % mod;
	}
	else{
		REP(i, abs(dir)){
			x = (x - 1) % mod;
			if (x < 0)
				x += mod;
		}
	}
	return x;

}

int charDiff(char a, char b){

	int fwd = pos[a], bck = pos[a];
	int c1 = 0, c2 = 0;

	while (fwd != pos[b]){
		fwd++;
		fwd %= 27;
		c1++;
	}
	while (bck != pos[b]){
		bck--;
		if (bck < 0)
			bck += 27;
		bck %= 27;
		c2--;
	}

	if (c1 > abs(c2))
		return c2;
	else
		return c1;
}

void printLetter(int off, int diff){

	if (off < 0){
		REP(i, abs(off))
			brainfuck.push_back('<');
	}
	else{
		REP(i, abs(off))
			brainfuck.push_back('>');
	}
	x = idMOD(x, 30, off);

	if (diff >= 0){
		REP(i, diff)
			brainfuck.push_back('+');
	}
	else{
		REP(i, abs(diff))
			brainfuck.push_back('-');
	}

	rune[x] = a[idMOD(pos[rune[x]], 27, diff)];
	brainfuck.push_back('.');
}

pair<int,int> findRune(char s){

	int offset, diff;
	offset = 0;
	diff = charDiff(rune[x], s);
	int min = offset + abs(diff);

	for (int i = 0, j = 0; i<=15 ;i++,j--){
		
		int opi = charDiff(rune[idMOD(x, 30, i)], s);
		if (abs(opi) + abs(i) < min){
			min = abs(opi) + abs(i);
			offset = i;
			diff = opi;
		}

		int opj = charDiff(rune[idMOD(x, 30, j)], s);
		if (abs(opj) + abs(j) < min){
			min = abs(opj) + abs(j);
			offset = j;
			diff = opj;
		}

	}

	return make_pair(offset, diff);
}

int main(){

	init();
	scanf("%[^\n]s", s);
	DB("String is \"%s\"\n", s);
	len = strlen(s);
	REP(i, len){
		pair<int, int> p = findRune(s[i]);
		printLetter(p.first, p.second);
	}
	brainfuck.push_back('\n');
	brainfuck.push_back(0);
	DB("The length of the final string is %d", brainfuck.size());
	printf("%s", brainfuck.c_str());
	return 0;
}

/*
#01 = 7
#02 = 37
#03 = 145
#04 = 29
#05 = 33
#06 = 25
#07 = 34
#08 = 94
#09 = 241
#10 = 107
#11 = 74
#12 = 227
#13 = 357
#14 = 722
#15 = 306
#16 = 44
#17 = 597
#18 = 236
#19 = 128
#20 = 323
#21 = 291
#22 = 284
#23 = 280
#24 = 1416


*/
