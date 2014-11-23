/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/COOK52/problems/PETERSEN

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

vector<int> graph[100];

char letter[] = { 'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E' };

stack<int> s;


int node(char L, int val){

	if (L == 'A'){
		if (val == 1)
			return 5;
		else if (val == 0)
			return 0;
		else
			return -1;
	}
	if (L == 'B'){
		if (val == 1)
			return 6;
		else if (val == 0)
			return 1;
		else
			return -1;
	}
	if (L == 'C'){
		if (val == 1)
			return 7;
		else if (val == 0)
			return 2;
		else
			return -1;
	}
	if (L == 'D'){
		if (val == 1)
			return 8;
		else if (val == 0)
			return 3;
		else
			return -1;
	}
	if (L == 'E'){
		if (val == 1)
			return 9;
		else if (val == 0)
			return 4;
		else
			return -1;
	}

}


void init(){

	graph[0].push_back(1);
	graph[0].push_back(4);
	graph[0].push_back(5);

	graph[1].push_back(0);
	graph[1].push_back(2);
	graph[1].push_back(6);

	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[2].push_back(7);

	graph[3].push_back(2);
	graph[3].push_back(4);
	graph[3].push_back(8);

	graph[4].push_back(0);
	graph[4].push_back(3);
	graph[4].push_back(9);

	graph[5].push_back(0);
	graph[5].push_back(7);
	graph[5].push_back(8);

	graph[6].push_back(1);
	graph[6].push_back(8);
	graph[6].push_back(9);

	graph[7].push_back(2);
	graph[7].push_back(5);
	graph[7].push_back(9);

	graph[8].push_back(3);
	graph[8].push_back(5);
	graph[8].push_back(6);

	graph[9].push_back(4);
	graph[9].push_back(6);
	graph[9].push_back(7);
}

int findPath(char str[]){

	
	int i = 0,len=strlen(str);

	s.push(node(str[i++], 0));

	while (!s.empty()){
		int cur = s.top();
		int found = -1;
		REP(k, 3){
			if (letter[graph[cur][k]] == str[i]){
				found = graph[cur][k];
				break;
			}
		}
		if (found!=-1){
			s.push(found);
			i++;
		}
		else{
			break;
		}

		if (i == len)
			return 1;
	}

	while (!s.empty()) s.pop();

	i = 0;
	s.push(node(str[i++], 1));

	while (!s.empty()){
		int cur = s.top();
		int found = -1;
		REP(k, 3){
			if (letter[graph[cur][k]] == str[i]){
				found = graph[cur][k];
				break;
			}
		}
		if (found != -1){
			s.push(found);
			i++;
		}
		else{
			break;
		}

		if (i == len)
			return 1;
	}
	return 0;

}


int main(){

	init();
	int t;
	char str[100000];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s",str);
		int ans = findPath(str);
		if (ans){
			int i = 0;
			while (!s.empty()){
				str[i++] = s.top()+'0';
				s.pop();
			}
			str[i] = '\0';
			REV(str, i);
			printf("%s\n", str);
		}
		else{
			puts("-1");
		}
	}
	return 0;
}

// Not Solved