/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/156360291d0fff175033ba449858985c969820d

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
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define DB(s,x) fprintf(stderr,s,x);
#define MS(x,n) memset(x,n,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int img[300][5000];
int w, h;
int line,interline, tail;
int note[6];
int ray[13];
int first = 0;

struct block{
	int ty;
	int w;
	int r[5];
};


void getvalues(){

	//Calculating Line width
	int found = 0;
	REP(j, w){
		REP(i, h){
			if (img[i][j] == 1){
				note[0] = i;
				while (img[i][j] == 1){
					line++;
					i++;
				}
				while (img[i][j] == 0){
					interline++;
					i++;
				}
				found = 1;
				break;
			}
		}
		if (found)
			break;
	}

	//Calculating Line heigts
	FOR(i, 1, 5)
		note[i] = note[i - 1] + line + interline;

	//Calculating the 13 Rays 
	ray[0] = note[0] - interline + line*1.5;
	FOR(i, 1, 12)
		ray[i] = i % 2 ? note[(i - 1) / 2] - line*1+1: note[(i - 1) / 2] + line*2;

	found = 0;
	REP(i, w){
		int c = 0;
		vector<int> rays;
		FOR(j, 2, 11){
			if (img[ray[j]][i] == 1){
				c++;
				rays.pb(j);
			}
		}
		if (c >= 4){
			while (img[ray[rays[2]]][i] == 1){
				tail++;
				i++;
			}
			break;
		}
	}

}

int main(){

	FILE *f = fopen("image.txt", "w");

	scanf("%d%d", &w, &h);
	int lastPixel = 0;
	while(lastPixel<w*h){
		char c;
		int n; 
		getchar();
		scanf("%c %d", &c, &n);
		c = c=='B' ? 1 : 0;
		REP(i, n){
			img[lastPixel/w][lastPixel%w] = c;
			lastPixel++;
		}
	}
	REP(i, h){
		REP(j, w)
			fprintf(f, "%c", img[i][j] ? 'O' : '.');
		fprintf(f,"\n");
	}
	fclose(f);

	getvalues();

	//0 for ball 1 For tail
	int gonein = 0;
	int hadgonein = 0;
	stack<block> stack;
	int bal = 0, tail = 0;
	REP(j, w){
		vector<int> rays;
		REP(i, 13){
			if (img[ray[i]][j] == 1)
				rays.pb(i);
		}
		if (rays.size() == 0 && stack.size() && stack.top().ty == 0 && gonein == 0 && stack.top().w<=3){
			hadgonein=gonein = 1;
		}
		else if (rays.size() == 2){
			block b;
			if (gonein)
				gonein = 2;
			if (stack.size())
				b = stack.top();
			if (stack.size() == 0 || b.ty == 1){
				block temp;
				temp.ty = 0;
				temp.w = 1;
				REP(i, 2)
					temp.r[i] = rays[i];
				stack.push(temp);
			}
			else{
				block b = stack.top();
				stack.pop();
				b.w++;
				stack.push(b);
			}
		}
		else if (rays.size() >= 3){
			block b;
			if (stack.size())
				b = stack.top();
			if (stack.size() == 0 || b.ty == 0){
				block temp;
				temp.ty = 1;
				temp.w = 1;
				REP(i, rays.size())
					temp.r[i] = rays[i];
				stack.push(temp);
			}
			else{
				block b = stack.top();
				stack.pop();
					b.w++;
				stack.push(b);
			}
		}
		else if (rays.size() == 0 && stack.size() == 2 && gonein%2==0){
			gonein = 0;
			block b = stack.top();
			if (first)
				printf(" ");
			else
				first = 1;
			if (b.ty == 1){
				stack.pop();
				if (stack.top().r[0] <= 11 && stack.top().r[0] >= 7)
					printf("%c", 'C' + (11 - stack.top().r[0]));
				else if (stack.top().r[0] == 6)
					printf("%c", 'A');
				else
					printf("%c", 'B');
				b = stack.top();
				stack.pop();
				if (!hadgonein)
					printf("Q");
				else
					printf("H");
			}
			else{
				int hehe = b.r[1];
				stack.pop();
				char notety;
				if (!hadgonein)
					notety = 'Q';
				else
					notety = 'H';

				b = stack.top();
				stack.pop();
				if (hehe <=5 && hehe >= 1)
					printf("%c", 'C' + (5 - hehe));
				else
					printf("%c", 'B');
				printf("%c", notety);
			}
			hadgonein = 0;
		}
	}
	return 0;
}

//Partially Solved 