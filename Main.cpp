#include <iostream>
#include <string>
#include "Mancala.h"
#include "FrontEndController.h"

#define FILENAME "AIfile.txt"


int main() {

	MancalaBoard mancala;
	FrontEndController frontend;

	matrix inputFile = frontend.readFile(FILENAME);

	int playerNum = mancala.populate(inputFile);
	std::cout << "Player: " << playerNum << std::endl;
	mancala.print();

	mancala.update(1, 3);
	mancala.print();

	mancala.update(1, 6);
	mancala.print();

	mancala.update(2, 3);
	mancala.print();

	mancala.update(1, 2);
	mancala.print();
}