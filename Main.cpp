#include <iostream>
#include <string>
#include "Mancala.h"
#include "FrontEndController.h"
#include "AI.h"

#define FILENAME "AIfile.txt"


int main() {

	MancalaBoard mancala;
	FrontEndController frontend;
	AI ai;

	matrix inputFile = frontend.readFile(FILENAME);
	int playerNum = mancala.populate(inputFile);

	std::cout << "Start Board" << std::endl;
	mancala.print();

	int bestCup = ai.bestMove(&mancala, 1);
	std::cout << "Player " << 1 << ". Best Cup: " << bestCup << std::endl;
	mancala.update(1, bestCup);
	mancala.print();

	bestCup = ai.bestMove(&mancala, 2);
	std::cout << "Player " << 2 << ". Best Cup: " << bestCup << std::endl;
	mancala.update(2, bestCup);
	mancala.print();
}