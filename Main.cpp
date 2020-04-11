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

	/*std::cout << "Start Board" << std::endl;
	mancala.print();*/

	int bestCup = ai.bestMove(&mancala, 1);


	// should just overwrite FILENAME, but i'm just testing
	frontend.writeFile("output.txt", playerNum, bestCup);
}