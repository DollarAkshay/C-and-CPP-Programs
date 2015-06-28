/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/149691757e4b0642ca9e698a828e429690fa660

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

struct node{
	int n;
	struct node* next[10];
};

struct node* List;
int ans = 0;

void append(struct node* p, char * s){

	while (s[0]){
		p->next[s[0] - '0'] = new node();
		ans++;
		p = p->next[s[0] - '0'];
		p->n = s[0] - '0';
		REP(i, 10)
			p->next[i] = NULL;
		s = s + 1;
	}


}

void addtoList(char s[100]){

	struct node* curr = List;
	int len = strlen(s);
	REP(i, len){
		if (curr && curr->next[s[i] - '0'])
			curr = curr->next[s[i] - '0'];
		else{
			append(curr, s + i);
			break;
		}
	
	}

}

int main(){

	List = new node();
	REP(i, 10)
		List->next[i] = NULL;
	int n;
	char s[100];
	scanf("%d", &n);
	REP(i, n){
		scanf("%s", &s);
		addtoList(s);
	}
	printf("%d", ans);
	return 0;
}

//