#include<iostream>
#include<algorithm>

using namespace std;


int minimax(int depth, int nodeIndex, bool maximizingPlayer,
			int values[], int alpha, int beta) {

	if (depth == 3) {		
		// Terminating condition. i.e leaf node is reached				
		return values[nodeIndex];
	}


	if (maximizingPlayer) {
		int best = -1000;
		for (int i = 0; i<2; i++) {
			int val = minimax(depth+1, nodeIndex*2+i,
							  false, values, alpha, beta);
			best = max( best, val);
			alpha = max(alpha, best);
			if (beta <= alpha)		// Condition Checking
				break;
		}
		return best;
	}
	else  {
		int best = +1000;

		for (int i = 0; i<2; i++) {
			int val = minimax(depth+1, nodeIndex*2+i,
							  true, values, alpha, beta);
			best = min(best, val);
			beta = min(beta, best);
			if (beta <= alpha)		// Condition Checking
				break;
		}
		return best;
	}

}

int main() {

	// Static Values
	int values[8] = { 3, 5, 6, 9, 1, 2, 0, -1 };
	int res = minimax(0, 0, true, values, -1000, +1000);

	cout << "The optimal value is : " << res <<endl;
	return 0;
		
}