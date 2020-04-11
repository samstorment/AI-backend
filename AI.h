#pragma once

#include "Mancala.h"


struct AI {

	int bestMove(MancalaBoard* mancala, int playerNum);
	int minimax(MancalaBoard* mancala, const int depth, const bool isMax);
	int alphaBeta(MancalaBoard* mancala, const int depth, const int alpha, const int beta, const bool isMax);
};
