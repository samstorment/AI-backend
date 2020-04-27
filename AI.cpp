#include "AI.h"
#include <algorithm>
#define POSITIVE_INFINITY  1000000.0
#define NEGATIVE_INFINITY -1000000.0


int AI::bestCup(MancalaBoard* mancala, int playerNum) {

	int opponentNum = playerNum == 1 ? 2 : 1;
	// the best score is initially terrible until we find any possible move
	double bestScore = playerNum == 1 ? NEGATIVE_INFINITY : POSITIVE_INFINITY;
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

			double score;

			// Update the board as if we chose the cup. Might have to handle the "You get another turn" case here/create a function for it?
			bool canGoAgain = mancala->update(playerNum, i + 1);
			if (canGoAgain) {
				// score = minimax(mancala, 0, playerNum);
				score = alphaBeta(mancala, 0, NEGATIVE_INFINITY, POSITIVE_INFINITY, playerNum);
			}
			else {
				// score = minimax(mancala, 0, opponentNum);
				score = alphaBeta(mancala, 0, NEGATIVE_INFINITY, POSITIVE_INFINITY, opponentNum);
			}

			// reset the board to its start state so we can run minimax the next valid move
			mancala->board = copyBoard;
			mancala->P1Mancala = copyP1Mancala;
			mancala->P2Mancala = copyP2Mancala;

			// right now this just selects the first non-empty cup as the best cup, since minimax isn't actually implemented
			if (playerNum == 1 && score >= bestScore) {
				bestScore = score;
				bestCup = i + 1;
			}
			else if (playerNum == 2 && score <= bestScore) {
				bestScore = score;
				bestCup = i + 1;
			}
		}
	}
	// return a value 1-6 for the bestCup in the given player's row.
	return bestCup;
}

// I'm just going to implement minimax first to get a better understanding of alpha-beta for later. Player 1 is always the maximizer
double AI::minimax(MancalaBoard* mancala, const int depth, const int playerNum) {


	if (mancala->gameOver() || depth == 4) {
		double weights[3] = { 1.0, 0.0, 0.0 };
		return getHeuristic(mancala, playerNum, weights);
	}

	// If it is the Maximizing player
	if (playerNum == 1) {
		double bestScore = NEGATIVE_INFINITY;
		for (int i = 0; i < mancala->board[playerNum - 1].size(); i++) {
			if (mancala->board[playerNum - 1][i] != 0) {
				matrix copyBoard = mancala->board;
				int copyP1Mancala = mancala->P1Mancala;
				int copyP2Mancala = mancala->P2Mancala;

				double score;
				bool canGoAgain = mancala->update(playerNum, i + 1);
				if (canGoAgain) {
					score = minimax(mancala, depth + 1, 1);
				}
				else {
					score = minimax(mancala, depth + 1, 2);
				}

				mancala->board = copyBoard;
				mancala->P1Mancala = copyP1Mancala;
				mancala->P2Mancala = copyP2Mancala;

				bestScore = std::max(score, bestScore);
			}
		}
		return bestScore;
	}
	// If it is minimizing player
	else {
		double bestScore = POSITIVE_INFINITY;
		for (int i = 0; i < mancala->board[playerNum - 1].size(); i++) {
			if (mancala->board[playerNum - 1][i] != 0) {
				matrix copyBoard = mancala->board;
				int copyP1Mancala = mancala->P1Mancala;
				int copyP2Mancala = mancala->P2Mancala;

				double score;
				bool canGoAgain = mancala->update(playerNum, i + 1);
				if (canGoAgain) {
					score = minimax(mancala, depth + 1, 2);
				}
				else {
					score = minimax(mancala, depth + 1, 1);
				}

				mancala->board = copyBoard;
				mancala->P1Mancala = copyP1Mancala;
				mancala->P2Mancala = copyP2Mancala;

				bestScore = std::min(score, bestScore);
			}
		}
		return bestScore;
	}
}


double AI::alphaBeta(MancalaBoard* mancala, const int depth, double alpha, double beta, const int playerNum) {

	if (mancala->gameOver() || depth == 10) {

		// only use the 2nd heuristic
		double weights[4] = { 0.0, 1.0, 0.0, 0.0 };
		return getHeuristic(mancala, playerNum, weights);
	}

	// If it is the Maximizing player
	if (playerNum == 1) {
		// initialize best score to a horrible value for the maximizing player (player 1)
		double bestScore = NEGATIVE_INFINITY;
		for (int i = 0; i < mancala->board[playerNum - 1].size(); i++) {
			if (mancala->board[playerNum - 1][i] != 0) {
				// copy the board
				matrix copyBoard = mancala->board;
				int copyP1Mancala = mancala->P1Mancala;
				int copyP2Mancala = mancala->P2Mancala;

				// check if the move lets the player go again
				double score;
				bool canGoAgain = mancala->update(playerNum, i + 1);
				if (canGoAgain) {
					// go again with the same player if can go again
					score = alphaBeta(mancala, depth + 1, alpha, beta, 1);
				}
				else {
					// swap to the other player if can't go again
					score = alphaBeta(mancala, depth + 1, alpha, beta, 2);
				}

				// reset the board back to the start state
				mancala->board = copyBoard;
				mancala->P1Mancala = copyP1Mancala;
				mancala->P2Mancala = copyP2Mancala;

				// get the best score, which is the larger of the current score and the best score up to now
				bestScore = std::max(score, bestScore);

				// find alpha and break if alpha > beta
				alpha = std::max(alpha, score);
				if (beta <= alpha) { break; }
			}
		}
		// return the best score after all valid move possibilites have been examined
		return bestScore;
	}
	// If it is minimizing player
	else {
		double bestScore = POSITIVE_INFINITY;
		for (int i = 0; i < mancala->board[playerNum - 1].size(); i++) {
			if (mancala->board[playerNum - 1][i] != 0) {
				matrix copyBoard = mancala->board;
				int copyP1Mancala = mancala->P1Mancala;
				int copyP2Mancala = mancala->P2Mancala;

				double score;
				bool canGoAgain = mancala->update(playerNum, i + 1);
				if (canGoAgain) {
					score = alphaBeta(mancala, depth + 1, alpha, beta, 2);
				}
				else {
					score = alphaBeta(mancala, depth + 1, alpha, beta, 1);
				}

				mancala->board = copyBoard;
				mancala->P1Mancala = copyP1Mancala;
				mancala->P2Mancala = copyP2Mancala;

				bestScore = std::min(score, bestScore);

				beta = std::min(beta, score);
				if (beta <= alpha) { break; }
			}
		}
		return bestScore;
	}
}

// if weights = {1.0, 0.0, 0.0, 0.0} only the first heuristic will be used
double AI::getHeuristic(MancalaBoard* mancala, int playerNum, double weights[4]) {
	return	weights[0] * findWin(mancala) +
			weights[1] * p1MinusP2(mancala) +
			weights[2] * p2MinusP1(mancala) +
			weights[3] * countMost(mancala);
}

// returns very good score (Infinity) if player1 has > half of the rocks, returns very bad score (-infinity) if player2 has > half of the rocks. Returns normal heuristic if neither of those is true
double AI::findWin(MancalaBoard* mancala) {
	int half = 24;
	if (mancala->P1Mancala > half) { return POSITIVE_INFINITY; }
	else if (mancala->P2Mancala > half) { return NEGATIVE_INFINITY; }

	// this heuristic should be changed if we want to make the AI VERY difficult. I'm not sure what heuristic would be best
	return (double)p1MinusP2(mancala);
}

// this one seems to perform the best, but I can still beat it when I play as player1 human
int AI::p1MinusP2(MancalaBoard* mancala) {
	return mancala->P1Mancala - mancala->P2Mancala;
}

// this one should be very bad
int AI::p2MinusP1(MancalaBoard* mancala) {
	return mancala->P2Mancala - mancala->P1Mancala;
}

// returns the count of P1's mancala if p1 has the most rocks. returns the negative count of p2's mancala if p2 has the most rocks
int AI:: countMost(MancalaBoard* mancala) {
	if (mancala->P2Mancala > mancala->P1Mancala) { return mancala->P2Mancala * -1; }
	else { return mancala->P1Mancala; }
}