#pragma once

#include <vector>
#include <string>
#include <iostream>

typedef std::vector<int> iarray;
typedef std::vector<iarray> matrix;
typedef std::vector<std::string> sarray;

struct MancalaBoard {

	matrix board;
	int P1Mancala;
	int P2Mancala;

	MancalaBoard();
	MancalaBoard(const MancalaBoard& mancala);

	void init();
	int populate(const matrix& cups);
	bool update(int player, int cup);
	bool gameOver();
	void print();

};