#include <iostream>
#include <string>
#include "Mancala.h"
#include "FrontEndController.h"

#define FILENAME "AIfile.txt"


int main() {

	MancalaBoard mancala;
	FrontEndController frontend;

	matrix inputFile = frontend.readFile(FILENAME);

	mancala.populate(inputFile);
	// mancala.print();
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 7; j++) {
			mancala.update(i - 1, j - 1);
		}
		std::cout << std::endl;
	}

}