#include "AI.h"
#define NEGATIVE_INFINITY -1000000
#define POSITIVE_INFINITY  1000000

int AI::bestMove(MancalaBoard* mancala, int playerNum) {

	// the best score is initially terrible until we find any possible move
	int bestScore = NEGATIVE_INFINITY;
	// bestCup will return -1 only if every cup is empty, which shouldn't ever happen as the game will be over
	int bestCup = -1;

	// for each cup in the given player's row
	for (int i = 0; i < mancala->board[playerNum - 1].size(); i++) {

		// if the cup is not empty, we can choose it
		if (mancala->board[playerNum - 1][i] != 0) {

			// copy the board state so we can loop through every move at this board state
			matrix copyBoard = mancala->board;
			int copyP1Mancala = mancala->P1Mancala;
			int copyP2Mancala = mancala->P2Mancala;

			// Update the board as if we chose the cup. Might have to handle the "You get another turn" case here/create a function for it?
			mancala->update(playerNum, i + 1);

			// Run minimax on the updated board state
			int score = minimax(mancala, 0, true);

			// reset the board to its start state so we can run minimax the next valid move
			mancala->board = copyBoard;
			mancala->P1Mancala = copyP1Mancala;
			mancala->P2Mancala = copyP2Mancala;

			// right now this just selects the first non-empty cup as the best cup, since minimax isn't actually implemented
			if (score > bestScore) {
				bestScore = score;
				bestCup = i + 1;
			}
		}
	}
	// return a value 1-6 for the bestCup in the given player's row.
	return bestCup;
}

// I'm just going to implement minimax first to get a better understanding of alpha-beta for later
int AI::minimax(MancalaBoard* mancala, const int depth, const bool isMax) {

	return 1;
}


int AI::alphaBeta(MancalaBoard* mancala, const int depth, const int alpha, const int beta, const bool isMax) {


	return 1;
}