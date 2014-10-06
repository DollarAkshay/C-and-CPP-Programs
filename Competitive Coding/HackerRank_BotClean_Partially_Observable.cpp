#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

char board[5][5];
int dx, dy;

void shortestpath(int bx, int by){

	int dist, min = 11;
	int i, j;

	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++){
			if (board[i][j] == 'd'){
				dist = abs(i - by) + abs(j - bx);
				if (dist < min){
					min = dist;
					dy = i;
					dx = j;
				}
			}
		}
	}

}

void nearestCorner(int bx, int by){

	int px[4] = { 1, 3, 3, 1 };
	int cx[4] = { 0, 4, 4, 0 };
	int py[4] = { 1, 1, 3, 3 };
	int cy[4] = { 0, 0, 4, 4 };
	int min = 11, i, dist;
	for (i = 0; i < 4; i++){
		if (board[cy[i]][cx[i]] == 'o'){
			dist = abs(py[i] - by) + abs(px[i] - bx);
			if (dist < min){
				min = dist;
				dy = py[i];
				dx = px[i];
			}
		}
	}
}


void next_move(int x, int y) {

	dx = -1;
	dy = -1;
	int i, j;

	shortestpath(x, y);
	if (dx == -1 || dy == -1){
		nearestCorner(x, y);
	}


	if (dx>x)
		printf("RIGHT\n");
	else if (dx<x)
		printf("LEFT\n");
	else if (dy<y)
		printf("UP\n");
	else if (dy>y)
		printf("DOWN\n");
	else{
		printf("CLEAN\n");
		board[dy][dx] = '-';
	}

}


int main(void) {

	int i, j; char c;
	FILE *f = fopen("data.txt", "r");

	if (f){
		for (i = 0; i < 5; i++){
			for (j = 0; j < 5; j++)
				fscanf(f, "%c", &board[i][j]);
			fscanf(f, "%c", &c);
		}
	}
	else{
		for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			board[i][j] = 'o';
	}

	int x, y;
	char line[6];

	//Reading Input
	cin >> y >> x;
	for (i = 0; i<5; i++) {
		cin >> line;
		int len = strlen(line);
		for (j = 0; j < len; j++){
			if (line[j] != 'o' && board[i][j] == 'o')
				board[i][j] = line[j];
		}
	}

	next_move(x, y);

	// Saving File
	f = fopen("data.txt", "w");
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++)
			fprintf(f, "%c", board[i][j]);
		fprintf(f, "\n", board[i][j]);
	}
	fclose(f);

	return 0;
}
