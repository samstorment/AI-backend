#pragma once
#include <vector>
#include <fstream>
#include <iostream>

typedef std::vector<int> iarray;
typedef std::vector<iarray> matrix;
typedef std::vector<std::string> sarray;

struct FrontEndController {
	matrix readFile(std::string filename);
	matrix processFile(const sarray& lines);
	void writeFile(std::string filename);
	sarray splitLine(std::string line, std::string delimiter);
	iarray toIntArray(const sarray& array);
};