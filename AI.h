#pragma once

#include "Mancala.h"

struct AI {
	int bestMove(MancalaBoard* mancala, int playerNum);
	int minimax(MancalaBoard* mancala, const int depth, const int playerNum);
	int alphaBeta(MancalaBoard* mancala, const int depth, int alpha, int beta, const int playerNum);
	int firstValidMove(MancalaBoard* mancala);
	int P1MinusP2(MancalaBoard* mancala);
	int howCloseToWinning(MancalaBoard* mancala);
	int howCloseIsOpponent(MancalaBoard* mancala);
	int stonesClose(MancalaBoard* mancala);
	int stonesFar(MancalaBoard* mancala);
	int stonesInMiddle(MancalaBoard* mancala);
};
