#include "Mancala.h"

MancalaBoard::MancalaBoard() {
	P1Mancala = 0;
	P2Mancala = 0;
}

// Copy ctor just for debugging
MancalaBoard::MancalaBoard(const MancalaBoard& mancala) {
	std::cout << "Mancala Board Copied!" << std::endl;
}

void MancalaBoard::init() {

	for (int i = 0; i < 2; i++) {
		iarray tempRow; 
		for (int j = 0; j < 6; j++) {
			tempRow.push_back(4);
		}
		board.push_back(tempRow);
	}
	P1Mancala = 0;
	P2Mancala = 0;
}

// return the player number that the AI is
int MancalaBoard::populate(const matrix& inputFile) {

	for (int i = 0; i < inputFile.size(); i++) {
		iarray tempRow;
		for (int j = 0; j < 6; j++) {
			tempRow.push_back(inputFile[i][j]);
		}
		board.push_back(tempRow);
	}
	P1Mancala = inputFile[0][6];
	P2Mancala = inputFile[1][6];

	// if there are 8 items in the first subarray, the AI is player 1, else AI is player 2
	if (inputFile[0].size() == 8) { return 1; }
	else { return 2; }
}

// returns true if the player gets to go again
bool MancalaBoard::update(int player, int cup) {
	int piecesInCup = board[player - 1][cup - 1];
	board[player - 1][cup - 1] = 0;
	int lastSide = -1, lastCup = -1;

	while (piecesInCup > 0) {
		int currentSide = player == 1 ? 0 : 1;
		int opponentSide = player == 1 ? 1 : 0;
		int currentCup;

		if (lastSide == opponentSide && lastCup == 5) {
			board[currentSide][0]++;
			currentCup = 1;
			piecesInCup--;
			lastSide = currentSide;
			lastCup = 0;
		}
		else {
			currentCup = cup;
		}

		while (currentCup < 6 && piecesInCup > 0) {
			board[currentSide][currentCup]++;
			lastSide = currentSide;
			lastCup = currentCup;
			piecesInCup--;
			currentCup++;
		}
		if (piecesInCup > 0) {
			if (player == 1) { P1Mancala++; }
			else { P2Mancala++; }
			piecesInCup--;
			lastSide = currentSide;
			lastCup = 6;
		} 
		int opponentCup = 0;
		
		while (opponentCup < 6 && piecesInCup > 0) {
			board[opponentSide][opponentCup]++;
			lastSide = opponentSide;
			lastCup = opponentCup;
			piecesInCup--;
			opponentCup++;
		}
	}
	// capture opponent
	if (lastSide == player - 1 && lastCup != 6 && board[lastSide][lastCup] == 1) {
		if (player == 1) {
			if (board[1][5 - lastCup] != 0) {
				int total = board[0][lastCup] + board[1][5 - lastCup];
				board[0][lastCup] = 0;
				board[1][5 - lastCup] = 0;
				P1Mancala += total;
			}
		}
		else {
			if (board[0][5 - lastCup] != 0) {
				int total = board[1][lastCup] + board[0][5 - lastCup];
				board[1][lastCup] = 0;
				board[0][5 - lastCup] = 0;
				P2Mancala += total;
			}
		}
		return false;
	} 
	// go again
	else if (lastSide == player - 1 && lastCup == 6) {
		return true;
	} 
	return false;
}

bool MancalaBoard::gameOver() {

	int total1 = 0, total2 = 0;
	for (int i = 0; i < 6; i++) {
		total1 += board[0][i];
		total2 += board[1][i];
		if (total1 + total2 > 0) {
			return false;
		}
	}
	return true;
}

void MancalaBoard::print() {

	// P2's row start's at the end
	std::cout << P2Mancala << " ";
	for (int i = int(board[1].size() - 1); i >= 0; i--) {
		std::cout << board[1][i] << " ";
	}

	std::cout << "X" << std::endl << "X ";

	for (int i = 0; i < board[0].size(); i++) {
		std::cout << board[0][i] << " ";
	}
	std::cout << P1Mancala << std::endl << std::endl;
}