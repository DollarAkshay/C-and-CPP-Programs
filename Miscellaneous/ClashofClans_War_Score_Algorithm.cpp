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
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int war_size;

vector<pair<double, string>> player;

double score[100];

void init() {

	player.push_back(make_pair(-1, "np"));
	player.push_back(make_pair(-1, "praveen"));
	player.push_back(make_pair(-1, "D!NE$[-]R!ZO\_"));
	player.push_back(make_pair(-1, "$Dollar Akshay$"));
	player.push_back(make_pair(-1, "wizard"));
	player.push_back(make_pair(-1, "kira"));
	player.push_back(make_pair(-1, "L3GeNd* Raj^"));
	player.push_back(make_pair(-1, "Batman"));
	player.push_back(make_pair(-1, "SHR"));
	player.push_back(make_pair(-1, "huccha venkat"));
	player.push_back(make_pair(-1, "VIKRAM"));
	player.push_back(make_pair(-1, "bsvk"));
	player.push_back(make_pair(-1, "luqman"));
	player.push_back(make_pair(-1, "Faizy"));
	player.push_back(make_pair(-1, "M@J@!"));
	player.push_back(make_pair(-1, "Jagdish"));
	player.push_back(make_pair(-1, "GIRI"));
	player.push_back(make_pair(-1, "Amogha"));
	player.push_back(make_pair(-1, "#khalBP"));
	player.push_back(make_pair(-1, "jk"));


}

double scoringAlgorithm(int stars[], int enemy[], int player) {

	double score = 0;

	REP(i, 2) {
		if (enemy[i]==0)
			score -= 0.25;
		else 
			score += stars[i]*(8-enemy[i]+player)/8.0;
	}
	
	return score;

}

int main(){

	init();

	printf("+----------------------------------------+\n");
	printf("|                                        |\n");
	printf("|        KMA WAR SCORE CALCULATOR        |\n");
	printf("|                                        |\n");
	printf("+----------------------------------------+\n");

	printf("\nEnter War Size : ");
	scanf("%d", &war_size);


	REP(i, player.size()) {
		int stars[2], enemy[2];
		cout<<"\nEnter Stars and #Enemy for "<<player[i].second<<endl;
		cout<<"First Attack : ";
		cin>>stars[0]>>enemy[0];
		cout<<"Second Attack : ";
		cin>>stars[1]>>enemy[1];
		player[i].first = scoringAlgorithm(stars, enemy, i+1);
	}

	SORT(player, player.size());
	REV(player, player.size());

	printf("\n\n~~~~~     SCORE LIST     ~~~~~\n\n");

	REP(i, player.size()) {
		printf(" %-15s : %.4lf \n\n", player[i].second.c_str(), player[i].first);
	}
		

	sp;
	return 0;
}

//