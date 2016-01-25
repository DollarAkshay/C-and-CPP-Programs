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
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

struct GameState {
	bool playerDraw;
	int scotch;
	int playerMoney, orpponentMoney;
};

const int MIN = 1<<31;
const int MAX = ~0 - MIN;

int player, opponent;


int main(){


	GameState game;
	char str[1000], *tok;
	int k, p1[1000], p2[1000];

	scanf("%d", &player);
	if (player==1) {
		opponent = 2;
		game.playerDraw = true;
	}
	else {
		opponent = 1;
		game.playerDraw = false;
	}
	while (scanf("%d", &p1[0])>0)
		printf("LOL\n");
	scanf("%d\n", &game.scotch);

	scanf("%[^\n]", str);
	getchar();
	tok = strtok(str, " ");
	for (k = 0; tok; k++) {
		p1[k] = atoi(tok);
		tok = strtok(NULL, " ");
	}
	scanf("%[^\n]", str);
	tok = strtok(str, " ");
	for (k = 0; tok; k++) {
		p2[k] = atoi(tok);
		tok = strtok(NULL, " ");
	}


	game.playerMoney = game.orpponentMoney = 100;
	REP(i, k) {
		if (p1[i]>p2[i]) {
			(player==1?game.playerMoney:game.orpponentMoney) -= p1[i];
		}
		else if (p2[i]>p1[i]) {
			(player==2?game.playerMoney:game.orpponentMoney) -= p2[i];
		}
		else {
			(game.playerDraw?game.playerMoney:game.orpponentMoney) -= p1[i];
			game.playerDraw = !game.playerDraw;
		}
	}

	sp;


	return 0;
}

//