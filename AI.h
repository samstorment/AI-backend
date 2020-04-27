#pragma once

#include "Mancala.h"

struct AI {

	int bestCup(MancalaBoard* mancala, int playerNum);
	double minimax(MancalaBoard* mancala, const int depth, const int playerNum);
	double alphaBeta(MancalaBoard* mancala, const int depth, double alpha, double beta, const int playerNum);
	double getHeuristic(MancalaBoard* mancala, int playerNum, double weights[4]);

	// Heuristics
	double findWin(MancalaBoard* mancala);
	int p1MinusP2(MancalaBoard* mancala);
	int p2MinusP1(MancalaBoard* mancala);
	int countMost(MancalaBoard* mancala);

};
