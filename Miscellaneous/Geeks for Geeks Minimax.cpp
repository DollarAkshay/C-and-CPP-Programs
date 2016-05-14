#include<iostream>
#include<algorithm>

using namespace std;

int values[4] = { 3, 5, 2, 9 };

int minimax(int depth, int nodeIndex, bool maximizingPlayer) {

	if (depth == 2) {		// Terminating condition. i.e leaf node is reached				
		return values[nodeIndex];
	}


	if (maximizingPlayer) {
		int best = -1000;

		int leftValue = minimax(depth+1, nodeIndex*2, false);		// Left Child
		best = max(best, leftValue);

		int rightValue = minimax(depth+1, nodeIndex*2 + 1, false);	// Right Child
		best = max(best, rightValue);

		return best;
	}
	else  {
		int best = 1000;

		int leftValue = minimax(depth+1, nodeIndex*2, false);		// Left Child
		best = min(best, leftValue);

		int rightValue = minimax(depth+1, nodeIndex*2 + 1, false);	// Right Child
		best = min(best, rightValue);

		return best;
	}

}

int main() {

	int res = minimax(0, 0, true);

	cout<<"The optimal value is : "<<res<<endl;

	system("pause");
	return 0;
		
}