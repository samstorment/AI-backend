#include "Mancala.h"


// Store the Player1Mancala in player1's row? same for p2
void MancalaBoard::populate(const matrix& inputFile) {
	int rows = inputFile.size();
	for (int i = 0; i < rows; i++) {
		iarray tempRow;
		for (int j = 0; j < 7; j++) {
			tempRow.push_back(inputFile[i][j]);
		}
		board.push_back(tempRow);
	}
}

bool MancalaBoard::update(const int& player, const int& cup) {
	int piecesInCup = board[player][cup];

	std::cout << piecesInCup;

	return true;
}



void MancalaBoard::print() {

	for (auto& i : board) {
		for (auto& j : i) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
}