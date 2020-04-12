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


	std::cout << "1, 2" << std::endl;
	mancala.update(1, 2);
	mancala.print();

	std::cout << "2, 1" << std::endl;
	mancala.update(2, 1);
	mancala.print();

	std::cout << "1, 3" << std::endl;
	mancala.update(1, 3);
	mancala.print();

	std::cout << "2, 1" << std::endl;
	mancala.update(2, 1);
	mancala.print();

	std::cout << "1, 4" << std::endl;
	mancala.update(1, 4);
	mancala.print();

	std::cout << "2, 5" << std::endl;
	mancala.update(2, 5);
	mancala.print();

	std::cout << "1, 5" << std::endl;
	mancala.update(1, 5);
	mancala.print();

	std::cout << "2, 5" << std::endl;
	mancala.update(2, 5);
	mancala.print();

	std::cout << "1, 6" << std::endl;
	mancala.update(1, 6);
	mancala.print();



	//int bestCup = ai.bestMove(&mancala, playerNum);

	//// should overwrite FILENAME instead of "output.txt"
	//frontend.writeFile("output.txt", playerNum, bestCup);
}