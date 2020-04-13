#pragma once

#include "Mancala.h"

struct AI {
	int bestMove(MancalaBoard* mancala, int playerNum);
	int minimax(MancalaBoard* mancala, const int depth, const int playerNum);
	int alphaBeta(MancalaBoard* mancala, const int depth, int alpha, int beta, const int playerNum);
};
