/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

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
#define pii pair<int,int>
#define MOD 1000000007

stack<int> st;

char code[100000];
char dict[100000][100];
char alphabet[26][10]{".-","-...","-.-.","-..",".","..-.",  // a-f
				"--.","....","..",".---","-.-",".-..",       // g-l
				"--","-.","---",".--.","--.-",".-.",         // m-r
				"...","-","..-","...-",".--","-..-",       //s-x
				"-.--","--.."};								  //y-z
int n;

void wordToMorse(char word[100]){

	char morse[100]="";
	int len = strlen(word);
	REP(i, len)
		strcat(morse, alphabet[word[i] - 'A']);
	strcpy(word, morse);

}

ll int matchM(char *s){

	if (s[0] == 0){
		return 1;
	}

	ll int res = 0;
	REP(i, n){
		if (!strncmp(dict[i], s, strlen(dict[i])))
			res += matchM(s + strlen(dict[i]));
	}

	return res;

}

int main(){



	scanf("%s", code);
	scanf("%d", &n);
	REP(i, n){
		scanf("%s", dict[i]);
		wordToMorse(dict[i]);
	}
	printf("%lld\n", matchM(code));
	return 0;
}

//