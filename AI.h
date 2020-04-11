#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include "Mancala.h"


struct AI {

	int minimax(MancalaBoard mancala, const int depth, const bool isMax);
	int alphaBeta(MancalaBoard mancala, const int depth, const int alpha, const int beta, const bool isMax);
};
