#include<iostream>
#include<algorithm>

using namespace std;

struct Move {
	int row, col;
};

char player, opponent;

// This function returns true if there are moves remaining on the board
// Returns false if there are no moves left to play.
bool isMovesLeft(char board[3][3]) {

	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			if (board[i][j]=='_')
				return true;
		}
	}
	return false;
}

// This is the evaluation function as discussed in the previous article
int evaluate(char b[3][3]) {

	// Checking for Rows for X or O victory.
	for (int row = 0; row<3; row++) {
		if (b[row][0]==b[row][1] && b[row][1]==b[row][2]) {
			if (b[row][0]==player) {
				return +10;
			}
			else if (b[row][0]==opponent) {
				return -10;
			}
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col<3; col++) {
		if (b[0][col]==b[1][col] && b[1][col]==b[2][col]) {
			if (b[0][col]==player) {
				return +10;
			}
			else if (b[0][col]==opponent) {
				return -10;
			}
		}
	}

	// Checking for Diagonals for X or O victory.
	if (b[0][0]==b[1][1] && b[1][1]==b[2][2]) {
		if (b[0][0]==player) {
			return +10;
		}
		else if (b[0][0]==opponent) {
			return -10;
		}
	}
	if (b[0][2]==b[1][1] && b[1][1]==b[2][0]) {
		if (b[0][2]==player) {
			return +10;
		}
		else if (b[0][2]==opponent) {
			return -10;
		}
	}

	// Else if none of them have won then return 0
	return 0;

}

// This is the minimax function.
// It considers all the possible ways the game can go
// and returns the value of the board
int minimax(char board[3][3], int depth, bool isMax) {

	int score = evaluate(board);
		
	// If Maximizer has won the game return his/her evaluated score
	if (score == 10) {					
		return score;
	}
	// If Minimizer has won the game return his/her evaluated score
	else if (score == -10) {			
		return score;
	}
	// If there are no more moves and no winner then it is a tie
	else if (isMovesLeft(board)==false) {	
		return 0;
	}


	if (isMax) {
		int best = -1000;
		for (int i = 0; i<3; i++) {
			for (int j = 0; j<3; j++) {		// For each cell

				if (board[i][j]=='_') {		// Check if cell is empty
					board[i][j] = player;	// Make the move
					// Call minimax recursively and choose the maximum value
					best = max( best , minimax(board, depth+1, !isMax) );
					board[i][j] = '_';		// Undo the move
				}
			}
		}
		return best;
	}
	else {
		int best = 1000;
		for (int i = 0; i<3; i++) {
			for (int j = 0; j<3; j++) {		// For each cell
				if (board[i][j]=='_') {		// Check if cell is empty
					board[i][j] = opponent;	// Make the move
					// Call minimax recursively and choose the minimum value
					best = min(best, minimax(board, depth+1, !isMax));	
					board[i][j] = '_';		// Undo the move
				}
			}
		}
		return best;
	}
}

// This will return the best possible move for the player
Move findBestMove(char board[3][3]) {

	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {		// For each cell
				
			if (board[i][j]=='_') {		// Check if celll is empty
				board[i][j] = player;	// Make the move
				int moveVal = minimax(board, 0, false);
				board[i][j] = '_';		// Undo the move
				// If the value of the current move is more than the best value
				if (moveVal > bestVal) {	
					bestMove.row = i;	// Save this move as the bestMove
					bestMove.col = j;
					bestVal = moveVal;	// Update the best value
				}

			}
		}
	}

	printf("The value of the best Move is : %d\n\n", bestVal);
	return bestMove;
}

// Driver code
int main() {

	player = 'x';
	opponent = player == 'x'?'o':'x';

	char board[3][3] = {
		{ 'x', 'o', 'x' },
		{ 'o', 'o', 'x' },
		{ '_', '_', '_' }
	};

	Move bestMove = findBestMove(board);

	printf("The Optimal Move is :\n");
	printf("ROW: %d COL: %d\n\n", bestMove.row, bestMove.col );

	getchar();
	return 0;
}