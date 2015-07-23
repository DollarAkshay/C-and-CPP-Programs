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

struct time_stamp{
	int hh, mm, ss;
	bool isNULL(){
		return !hh && !mm & !ss;
	}
	void operator+=(time_stamp &t){
		ss = ss+t.ss;
		mm = mm+t.mm + ss/60;
		hh = hh+t.hh + mm/60;
		ss %= 60;
		mm %= 60;
	}
	void operator-=(time_stamp &t){
		ss = ss-t.ss;
		if (ss<0){
			ss+=60;
			mm--;
		}
		mm = mm-t.mm;
		if (mm<0){
			mm += 60;
			hh--;
		}
		hh = hh-t.hh;
	}
	bool operator < (time_stamp &t){
		return (hh<t.hh) || (hh==t.hh && mm<t.mm) || (hh==t.hh && mm==t.mm && ss==t.ss);
	}
};

struct problem{
	int score, penalties;
	time_stamp t;
};

struct user{
	char rank,username[100],realname[100];
	int score, solved;
	time_stamp totalTime;
	problem p[10];
};

user u[1000];

user optimal[1000];

int participants, totalProblems;
time_stamp elapsed,penalty;

bool compare(user l, user r){
	return l.totalTime<r.totalTime;
}

void printSeperator(int name){

	char blank[100];
	REP(i, name)
		blank[i] = '-';
	blank[name] = 0;

	printf(" +-----+-%s-+------+----+----------+",blank);

	REP(i, totalProblems){
		printf("-----+");
	}
	printf("\n");

}

void printHeader(int name){

	int width = 35 + name + 6*totalProblems;
	printf("\n");
	REP(i, width/2)
		printf(" ");
	printf("LEADERBOARD\n");
}

void printLeaderBoard(user u[]){


	int longestName = 0;
	FOR(i, 1, participants)
		longestName = max(longestName, (int)strlen(u[i].realname));
	
	printHeader(longestName);

	printSeperator(longestName);
	FOR(i, 1, participants){
		printf(" | %3d | %-*s | %4d | %2d | %02d:%02d:%02d |",
			   u[i].rank,longestName,u[i].realname,u[i].score,u[i].solved,
			   u[i].totalTime.hh, u[i].totalTime.mm, u[i].totalTime.ss);
		REP(j, totalProblems){
			if (u[i].p[j].score){
				printf(" %3d |", u[i].p[j].score);
			}
			else{
				if (u[i].p[j].penalties)
					printf(" %3d |", u[i].p[j].penalties);
				else
					printf("     |");
			}
		}
		printf("\n");
		printSeperator(longestName);
	}

	printf("\n");

}

int main(){

	printf("\nEnter the Number of Participants : ");
	scanf("%d", &participants);
	printf("\nEnter the Number of Problems : ");
	scanf("%d", &totalProblems);
	printf("\nEnter the Time Elapsed : ");
	scanf("%d:%d:%d", &elapsed.hh, &elapsed.mm, &elapsed.ss );
	printf("\nEnter the Time Penalty : ");
	scanf("%d:%d:%d", &penalty.hh, &penalty.mm, &penalty.ss);

	// Reading the Data
	printf("Enter the Data :\n");
	FOR(i, 1, participants){
		char duplicateUserName[100];
		scanf("%d %s\n", &u[i].rank,u[i].username);
		scanf("%[^\n]s", &u[i].realname);
		scanf("%s", duplicateUserName);
		assert( strcmp(duplicateUserName, u[i].username)==0 );
		scanf("%d %d", &u[i].score, &u[i].solved);
		scanf("%d:%d:%d", &u[i].totalTime.hh, &u[i].totalTime.mm, &u[i].totalTime.ss);
		REP(j, totalProblems){
			char data[100];
			scanf("%s", data);
			if (strcmp("N/A", data)==0){
				u[i].p[j].penalties = 0;
				u[i].p[j].score = 0;
				u[i].p[j].t.hh = u[i].p[j].t.mm = u[i].p[j].t.ss = 0;
			}
			else{
				int score = stoi(data);
				if (score<0){
					u[i].p[j].penalties = -score;
					u[i].p[j].score = 0;
					u[i].p[j].t.hh = u[i].p[j].t.mm = u[i].p[j].t.ss = 0;
				}
				else{
					u[i].p[j].score = score;
					scanf("%d:%d:%d (%d)", &u[i].p[j].t.hh, &u[i].p[j].t.mm, &u[i].p[j].t.ss, &u[i].p[j].penalties);
				}
			}
		}
	}

	printLeaderBoard(u);

	FOR(i, 1, participants){
		optimal[i] = u[i];
		optimal[i].score = 400;
		optimal[i].solved = totalProblems;
		REP(j, totalProblems){
			if (optimal[i].p[j].score==0){
				optimal[i].totalTime += elapsed;
				REP(k, optimal[i].p[j].penalties)
					optimal[i].totalTime += penalty;
			}
			else if (optimal[i].p[j].score<100){
				optimal[i].totalTime -= optimal[i].p[j].t;
				optimal[i].totalTime += elapsed;
			}
			optimal[i].p[j].score = 100;
		}
	}

	// Sorting the Leader Board
	sort(begin(optimal)+1, begin(optimal)+participants+1, compare);
	FOR(i, 1, participants)
		optimal[i].rank = i;

	printLeaderBoard(optimal);

	sp;
	return 0;
}

/*
1	 DollarAkshay
Akshay L Aradhya
DollarAkshay
400	4	03:07:09
100
01:12:37 (0)
100
01:09:29 (0)
100
00:19:15 (1)
100
00:25:48 (0)
2	 aman45
Aman Agarwal
aman45
350	4	03:48:00
100
00:56:14 (0)
50
01:12:45 (0)
100
00:54:46 (0)
100
00:44:15 (0)

*/