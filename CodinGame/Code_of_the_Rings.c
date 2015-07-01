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


#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(s,x) fprintf(stderr,s,x)
#define ll long long
#define MOD 1000000007

const int testing = 0;
int score = 0;

char a[27] = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char s[1000],rune[30];
int len, x;
int pos[255];

struct pair{
	int first, second;
};

int mini(int a, int b){
	return a > b ? b : a;
}


void init(){

	x = 0;
	REP(i, 27)
		pos[a[i]] = i;
	REP(i, 30)
		rune[i] = ' ';

}

int posMOD(int n, int mod){

	int x = n%mod;
	if (x < 0)
		x += mod;
	return x;
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

void printLetter(int off, int diff,int notloop){

	if (off < 0){
		REP(i, abs(off))
			printf("<");
	}
	else{
		REP(i, abs(off))
			printf(">");
	}
	x = idMOD(x, 30, off);

	if (diff >= 0){
		REP(i, diff)
			printf("+");
	}
	else{
		REP(i, abs(diff))
			printf("-");
	}

	if (notloop)
		rune[x] = a[idMOD(pos[rune[x]], 27, diff)];
		
}

struct pair findRune(char s){

	int offset, diff;
	int min = 100;

	for (int i = 15, j = -15; i>=0 ;i--,j++){
		
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
	struct pair tempor = { offset, diff };
	return tempor;
}

int checkIncreasingSequence(int i){

	int j = i, k = posMOD(pos[s[i+1]]-pos[s[i]],27);

	if (k > 13)
		return i;

	while (s[j] && posMOD(pos[s[j + 1]] - pos[s[j]], 27) == k)
		j++;
	j++;
	j -= i;
	int aa = charDiff(rune[x], s[i]);
	if (abs(aa) - 2 * j + 34 > j*k - k)
		return i;
	else{
		if (j >= 26){
			printLetter(0, aa, 1);
			rune[x] = a[idMOD(pos[rune[x]], 27, 26*k)];
			
			printLetter(-1, 0, 0);
			int zz = charDiff(rune[x], 'Z');
			printLetter(0, zz, 0); // n = 26
			rune[x] = ' ';
			printf("[");
			printLetter(1, 0, 1);
			printf(".");
			printLetter(0, k, 0);
			printLetter(-1, 0, 0);
			printLetter(0, -1, 0);
			printf("]");
			printLetter(1, 0, 1);
			return checkIncreasingSequence(i + 26);
		}
		else{
			printLetter(0, aa, 0);
			rune[x] = a[idMOD(pos[rune[x]], 27, abs(j)*k)];
			printLetter(-1, 0, 0);
			int zz = charDiff(rune[x], a[j]);
			printLetter(0, zz, 0); // n = j
			rune[x] = ' ';
			printf("[");
			printLetter(1, 0, 1);
			printf(".");
			printLetter(0, k, 0);
			printLetter(-1, 0, 0);
			printLetter(0, -1, 0);
			printf("]");
			return i+j;
		}

	}

}

int checkSubString(int nx){

	
	if (nx >= len)
		return nx;

	int j = 0,k;
	char ss[500];
	FOR(i, 2, mini(20,len/8)){
		char sub[500],sub_i=0;
		REP(mm, i)
			sub[sub_i++]=s[nx + mm];
		sub[sub_i] = 0;
		if (sub_i == 0)
			return nx;
		j = 0;
		while (!strncmp(sub,s+nx+j*i, i)){
			j++;
		}
		if (j >= 8){
			strcpy(ss, sub);
			k = i;
			break;
		}
	}
	if (j < 8)
		return nx;


	REP(i, k){
		int cd = charDiff(rune[x], ss[i]);
		printLetter(0, cd, 1);
		printLetter(1, 0, 1);
	}
	if (j >= 26){
		printLetter(0, -1, 0);
		printf("[");
		REP(i, k)
			printLetter(-1, 0, 1);
		REP(i, k){
			printf(".");
			printLetter(1, 0, 1);
		}
		printLetter(0, -1, 0);
		printf("]");
		REP(i, k)
			printLetter(-1, 0, 1);
		return checkSubString(nx + 26*k);
	}
	else{
		int cd = charDiff(rune[x], a[j]);
		printLetter(0, cd, 0);
		printf("[");
		REP(i, k)
			printLetter(-1, 0, 1);
		REP(i, k){
			printf(".");
			printLetter(1, 0, 1);
		}
		printLetter(0, -1, 0);
		printf("]");
		return nx + j*k;
	}

	return 0;
}


int main(){


	int tc = testing ? 24 : 1;
	FILE *f = fopen("testcase.txt", "r");
	FILE *fout = fopen("out4.txt", "w");


	REP(t, tc){
		init();
		if (testing){
			fscanf(f, "%[^\n]s", s);
			fgetc(f);
		}
		else
			scanf("%[^\n]s", s);
		DB("The String is \"%s\"\n", s);
		len = strlen(s);


		REP(i, len){
			int new_i = checkIncreasingSequence(i);
			if (new_i != i){
				i = new_i-1;
				continue;
			}
			int new_i2 = checkSubString(i);
			if (new_i2 != i){
				i = new_i2 - 1;
				continue;
			}
			
			struct pair p = findRune(s[i]);
			printLetter(p.first, p.second,1);
			printf(".");
		}
		printf("\n");
		printf(0);

	}
	fclose(f);
	fclose(fout);
	return 0;
}

/*
Testcase : #01 = 7
Testcase : #02 = 37
Testcase : #03 = 152
Testcase : #04 = 29
Testcase : #05 = 33
Testcase : #06 = 23
Testcase : #07 = 34
Testcase : #08 = 94
Testcase : #09 = 193
Testcase : #10 = 107
Testcase : #11 = 74
Testcase : #12 = 226
Testcase : #13 = 358
Testcase : #14 = 716
Testcase : #15 = 294
Testcase : #16 = 44
Testcase : #17 = 597
Testcase : #18 = 243
Testcase : #19 = 128
Testcase : #20 = 323
Testcase : #21 = 291
Testcase : #22 = 284
Testcase : #23 = 243
Testcase : #24 = 1438
You final score is 5968


*/
