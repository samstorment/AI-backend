#include <iostream>
#include <string>
#include "Mancala.h"
#include "FrontEndController.h"
#include "AI.h"

#define FILENAME "AIfile.txt"

// To use in the frontend, build (ctrl + b) in release mode. When selecting the AI in the frontend, choose AI-backend.exe from the x64/Release folder (x86 for an x86 build)
int main() {

	MancalaBoard mancala;
	FrontEndController frontend;
	AI ai;

	matrix inputFile = frontend.readFile(FILENAME);

	int playerNum = mancala.populate(inputFile);

	int bestCup = ai.bestMove(&mancala, playerNum);

	frontend.writeFile(FILENAME, playerNum, bestCup);
}