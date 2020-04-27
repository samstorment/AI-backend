#include <iostream>
#include <string>
#include "Mancala.h"
#include "FrontEndController.h"
#include "AI.h"

/* For thread sleep */
//#include <chrono>
//#include <thread>


#define FILENAME "AIfile.txt"

// To use in the frontend, build (ctrl + b) in release mode. When selecting the AI in the frontend, choose AI-backend.exe from the x64/Release folder (x86 for an x86 build)
int main() {

	// 1.5ms delay before doing anything
	// std::this_thread::sleep_for(std::chrono::milliseconds(1500));

	MancalaBoard mancala;
	FrontEndController frontend;
	AI ai;

	matrix inputFile = frontend.readFile(FILENAME);

	int playerNum = mancala.populate(inputFile);

	int bestCup = ai.bestCup(&mancala, playerNum);

	frontend.writeFile(FILENAME, playerNum, bestCup);
}