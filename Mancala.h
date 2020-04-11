#pragma once

#include <vector>
#include <string>
#include <iostream>

typedef std::vector<int> iarray;
typedef std::vector<iarray> matrix;
typedef std::vector<std::string> sarray;

struct MancalaBoard {

	matrix board;
	// I think i'd rather just store these at the end of the board matrix rows for player 1 and 2
	int player1Mancala{ 0 };
	int player2Mancala{ 0 };

	void populate(const matrix& cups);
	bool update(const int& player, const int& cup);
	void print();

	// need to implement Aaron's updateBoard method

};