#include "AI.h"
#include <algorithm>
#define NEGATIVE_INFINITY -1000000
#define INFINITY  1000000

int AI::bestMove(MancalaBoard* mancala, int playerNum) {

	int opponentNum = playerNum == 1 ? 2 : 1;
	// the best score is initially terrible until we find any possible move
	int bestScore = playerNum == 1 ? NEGATIVE_INFINITY : INFINITY;
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

			int score;

			// Update the board as if we chose the cup. Might have to handle the "You get another turn" case here/create a function for it?
			bool canGoAgain = mancala->update(playerNum, i + 1);
			if (canGoAgain) {
				// score = minimax(mancala, 0, playerNum);
				score = alphaBeta(mancala, 0, NEGATIVE_INFINITY, INFINITY, playerNum);
			}
			else {
				// score = minimax(mancala, 0, opponentNum);
				score = alphaBeta(mancala, 0, NEGATIVE_INFINITY, INFINITY, opponentNum);
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
int AI::minimax(MancalaBoard* mancala, const int depth, const int playerNum) {


	if (mancala->gameOver() || depth == 4) {

		// This return value is some heurisitic that evaluates how good the board state is. This current return value is a very lazy heuristic.
		return mancala->P1Mancala - mancala->P2Mancala;
	}

	// If it is the Maximizing player
	if (playerNum == 1) {
		int bestScore = NEGATIVE_INFINITY;
		for (int i = 0; i < mancala->board[playerNum - 1].size(); i++) {
			if (mancala->board[playerNum - 1][i] != 0) {
				matrix copyBoard = mancala->board;
				int copyP1Mancala = mancala->P1Mancala;
				int copyP2Mancala = mancala->P2Mancala;

				int score;
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
	else if (playerNum == 2) {
		int bestScore = INFINITY;
		for (int i = 0; i < mancala->board[playerNum - 1].size(); i++) {
			if (mancala->board[playerNum - 1][i] != 0) {
				matrix copyBoard = mancala->board;
				int copyP1Mancala = mancala->P1Mancala;
				int copyP2Mancala = mancala->P2Mancala;

				int score;
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


int AI::alphaBeta(MancalaBoard* mancala, const int depth, int alpha, int beta, const int playerNum) {

	if (mancala->gameOver() || depth == 10) {


		// This return value is some heurisitic that evaluates how good the board state is. This current return value is a very lazy heuristic.
		return mancala->P1Mancala - mancala->P2Mancala;
	}

	// If it is the Maximizing player
	if (playerNum == 1) {
		int bestScore = NEGATIVE_INFINITY;
		for (int i = 0; i < mancala->board[playerNum - 1].size(); i++) {
			if (mancala->board[playerNum - 1][i] != 0) {
				matrix copyBoard = mancala->board;
				int copyP1Mancala = mancala->P1Mancala;
				int copyP2Mancala = mancala->P2Mancala;

				int score;
				bool canGoAgain = mancala->update(playerNum, i + 1);
				if (canGoAgain) {
					score = alphaBeta(mancala, depth + 1, alpha, beta, 1);
				}
				else {
					score = alphaBeta(mancala, depth + 1, alpha, beta, 2);
				}

				mancala->board = copyBoard;
				mancala->P1Mancala = copyP1Mancala;
				mancala->P2Mancala = copyP2Mancala;

				bestScore = std::max(score, bestScore);

				alpha = std::max(alpha, score);
				if (beta <= alpha) { break; }
			}
		}
		return bestScore;
	}
	// If it is minimizing player
	else if (playerNum == 2) {
		int bestScore = INFINITY;
		for (int i = 0; i < mancala->board[playerNum - 1].size(); i++) {
			if (mancala->board[playerNum - 1][i] != 0) {
				matrix copyBoard = mancala->board;
				int copyP1Mancala = mancala->P1Mancala;
				int copyP2Mancala = mancala->P2Mancala;

				int score;
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