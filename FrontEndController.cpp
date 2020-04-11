#include "FrontEndController.h"
#include <string>

matrix FrontEndController::readFile(const std::string& filename) {
	matrix processedInput;
	sarray lines;
	lines.reserve(5);

	std::ifstream file(filename);
	if (file.is_open()) {
		std::string line;
		int i = 0;
		while (std::getline(file, line)) {
			lines.push_back(line.c_str());
			// std::cout << lines[i] << std::endl;
			i++;
		}
		file.close();
	}
	return processFile(lines);
}

matrix FrontEndController::processFile(const sarray& lines) {
	
	matrix fileData;

	std::string playerNum = lines[0];

	std::string next = lines[1];
	sarray player1Row = splitLine(next, ", ");

	next = lines[2];
	sarray player2Row = splitLine(next, ", ");

	std::string p1Mancala = lines[3];
	std::string p2Mancala = lines[4];

	player1Row.push_back(p1Mancala);
	player2Row.push_back(p2Mancala);

	if (playerNum == "1") {
		player1Row.push_back(playerNum);
	}
	else {
		player2Row.push_back(playerNum);
	}

	fileData.push_back(toIntArray(player1Row));
	fileData.push_back(toIntArray(player2Row));

	return fileData;
}

sarray FrontEndController::splitLine(std::string line, const std::string& delimiter) {

	sarray result;
	size_t position = 0;
	std::string substr;

	while ((position = line.find(delimiter)) != std::string::npos) {
		substr = line.substr(0, position);
		// std::cout << substr << std::endl;
		result.push_back(substr);
		line.erase(0, position + delimiter.length());
	}
	//std::cout << line << std::endl;
	result.push_back(line);

	return result;
}

// convert string array to int array
iarray FrontEndController::toIntArray(const sarray& array) {

	iarray convert;

	for (auto& i : array) {
		convert.push_back(stoi(i));
	}

	return convert;
}