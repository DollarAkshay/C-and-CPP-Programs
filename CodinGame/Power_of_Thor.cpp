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

int main(){

	float lx, ly, tx, ty;
	cin >> lx >> ly >> tx >> ty;

	float dx = 0, dy = 0;

	// game loop
	while (1) {

		int E;
		cin >> E;

		float e = max(abs(lx - tx), abs(ly - ty));

		dx += (lx - tx) / e;
		dy += (ly - ty) / e;

		fprintf(stderr, "tx = %f  ty = %f\n", tx, ty);
		fprintf(stderr, "dx = %f  dy = %f\n", dx, dy);

		if (dy >= 1){
			printf("S");
			dy--;
			ty++;
		}
		else if (dy <= -1){
			printf("N");
			dy++;
			ty--;
		}
		if (dx >= 1){
			printf("E");
			dx--;
			tx++;
		}
		else if (dx <= -1){
			printf("W");
			dx++;
			tx--;
		}
		puts("");
	}

	return 0;
}